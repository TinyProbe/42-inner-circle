/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:17:06 by tkong             #+#    #+#             */
/*   Updated: 2023/11/29 22:17:06 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.h"

#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>

#include <iostream>

#include "common.h"

namespace irc {

static int const kMaxBacklog = 128;

Server::Server() : sock_(-1),
                   port_(-1),
                   request_callback_(*this) {
  int sock = socket(PF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    throw std::runtime_error(std::string("socket: ") +
                             std::string(strerror(errno)));
  }
  int flag = 1;
  setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(int));

  struct hostent *hostinfo;
  if ((hostinfo = gethostbyname("www.google.com")) == NULL) {
    throw std::runtime_error(std::string("gethostbyname: ") +
                             std::string(strerror(errno)));
  }

  struct sockaddr_in target_addr;
  bzero(&target_addr, sizeof(struct sockaddr_in));
  target_addr.sin_family = AF_INET;
  target_addr.sin_port = htons(80);
  memcpy(&target_addr.sin_addr, hostinfo->h_addr, hostinfo->h_length);
  if (connect(sock,
              (struct sockaddr *) &target_addr,
              sizeof(struct sockaddr_in)) == -1) {
    throw std::runtime_error(std::string("connect: ") +
                             std::string(strerror(errno)));
  }

  struct sockaddr_in serv_addr;
  socklen_t serv_len = sizeof(struct sockaddr_in);
  bzero(&serv_addr, serv_len);
  if (getsockname(sock,
                  (struct sockaddr *) &serv_addr,
                  &serv_len) == -1) {
    throw std::runtime_error(std::string("getsockname: ") +
                             std::string(strerror(errno)));
  }

  int ip = ntohl(serv_addr.sin_addr.s_addr);
  host_ += std::to_string(((unsigned char *) &ip)[3]) + '.';
  host_ += std::to_string(((unsigned char *) &ip)[2]) + '.';
  host_ += std::to_string(((unsigned char *) &ip)[1]) + '.';
  host_ += std::to_string(((unsigned char *) &ip)[0]);

  close(sock);
}

int Server::getSocket() const { return sock_; }

std::string const &Server::getHost() const { return host_; }

UMint_Client &Server::getConnection() { return connection_; }

UMstring_int &Server::getNickToSock() { return nick_to_sock_; }

UMstring_Channel &Server::getChannelMap() { return channel_map_; }

Client &Server::getClient(int sock) {
  UMint_Client::iterator it = connection_.find(sock);
  if (it == connection_.end()) {
    throw std::runtime_error("getClient: invalid key");
  }
  return it->second;
}

Client &Server::getClient(std::string const &nick) {
  UMstring_int::iterator it = nick_to_sock_.find(nick);
  if (it == nick_to_sock_.end()) {
    throw std::runtime_error("getClient: invalid key");
  }
  return connection_[it->second];
}

void Server::setPort(int port) {
  if (port < 0 || port > 65535) {
    throw std::runtime_error("port: 0 <= port <= 65535");
  }
  port_ = port;
  size_t pos = host_.find(':');
  if (pos != std::string::npos) {
    host_.resize(pos);
  }
  host_ += ':';
  host_ += std::to_string(port);
}

void Server::setPassword(std::string const &password) {
  if (password.size() < 4 || password.size() > 20) {
    throw std::runtime_error("password: 4 <= password <= 20");
  }
  for (int i = 0; i < (int)password.size(); ++i) {
    if (!isprint(password[i])) {
      throw std::runtime_error("password: format error(unprintable)");
    }
  }
  password_ = password;
}

bool Server::verify(std::string const &password) const {
  return password_ == password;
}

void Server::standby() {
  if (sock_ != -1) { close(sock_); }

  if ((sock_ = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
    throw std::runtime_error(std::string("socket: ") +
                             std::string(strerror(errno)));
  }
  fcntl(sock_, F_SETFL, O_NONBLOCK);

  int flag[] = { 1 };
  setsockopt(sock_, SOL_SOCKET, SO_REUSEADDR, flag, sizeof(int));

  struct sockaddr_in serv_addr;
  bzero((void *) &serv_addr, sizeof(struct sockaddr_in));
  serv_addr.sin_family      = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port        = htons(port_);

  if (bind(sock_,
           (struct sockaddr *) &serv_addr,
           sizeof(struct sockaddr_in)) == -1) {
    throw std::runtime_error(std::string("bind: ") +
                             std::string(strerror(errno)));
  }

  if (listen(sock_, kMaxBacklog) == -1) {
    throw std::runtime_error(std::string("listen: ") +
                             std::string(strerror(errno)));
  }
}

void Server::preProcess() {
  UMint_Client::iterator i;
  for (i = connection_.begin(); i != connection_.end(); ++i) {
    i->second.setWrite(false);
  }
}

int Server::accept() {
  int client_sock;
  struct sockaddr_in client_addr;
  socklen_t client_len = sizeof(struct sockaddr_in);
  bzero(&client_addr, sizeof(struct sockaddr_in));

  if ((client_sock = ::accept(sock_,
                              (struct sockaddr *) &client_addr,
                              &client_len)) == -1) {
    if (errno == EWOULDBLOCK) {
      std::cerr << std::string("accept: ") +
                   std::string(strerror(errno)) << std::endl;
    } else {
      throw std::runtime_error(std::string("accept: ") +
                               std::string(strerror(errno)));
    }
  }
  fcntl(client_sock, F_SETFL, O_NONBLOCK);

  Client &client = connection_[client_sock];
  client.setSocket(client_sock);
  client.setAddress(client_addr);
  return client_sock;
}

void Server::disconnect(int sock) {
  UMint_Client::iterator it = connection_.find(sock);
  if (it != connection_.end()) {
    UMstring_Channel::iterator i;
    for (i = channel_map_.begin(); i != channel_map_.end(); ) {
      i->second.part(it->second.getNick());
      if (i->second.getJoinedClient().empty()) {
        i = channel_map_.erase(i);
      } else {
        ++i;
      }
    }

    close(it->first);
    nick_to_sock_.erase(it->second.getNick());
    connection_.erase(it);
  }
}

void Server::disconnect(std::string const &nick) {
  UMstring_int::iterator it = nick_to_sock_.find(nick);
  if (it != nick_to_sock_.end()) {
    UMstring_Channel::iterator i;
    for (i = channel_map_.begin(); i != channel_map_.end(); ) {
      i->second.part(nick);
      if (i->second.getJoinedClient().empty()) {
        i = channel_map_.erase(i);
      } else {
        ++i;
      }
    }

    close(it->second);
    connection_.erase(it->second);
    nick_to_sock_.erase(it);
  }
}

void Server::response(Request const &req, RequestPool &requests) {
  request_callback_(req, requests);
}

} // namespace irc
