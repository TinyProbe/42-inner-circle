/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migo <migo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:17:10 by migo              #+#    #+#             */
/*   Updated: 2023/11/29 22:17:10 by migo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRCSERV_CLIENT_H_
#define IRCSERV_CLIENT_H_

#include <netinet/in.h>

#include <string>
#include <unordered_map>

#include "Request.h"

namespace irc {

typedef std::unordered_map<std::string, bool> UMstring_bool;

class Client {
 public:
  Client() : auth_(), sock_(-1),
             nick_("*"), user_("*"),
             real_("*"), host_("*"),
             can_write_() {
    bzero(&addr_, sizeof(struct sockaddr_in));
  }
  ~Client() {}

  bool getAuth() const;
  std::string const &getPassword() const;
  int getSocket() const;
  struct sockaddr_in const &getAddress() const;
  void setAuth(bool auth);
  void setPassword(std::string const &password);
  void setSocket(int sock);
  void setAddress(struct sockaddr_in const &addr);

  std::string const &getNick() const;
  std::string const &getUser() const;
  std::string const &getReal() const;
  std::string const &getHost() const;
  void setNick(std::string const &nick);
  void setUser(std::string const &user);
  void setReal(std::string const &real);
  void setHost(std::string const &host);
  std::string getIdentify() const;

  std::string &getBuffer();
  bool canWrite() const;
  void setWrite(bool can_write);

  UMstring_bool &getJoinedChannel();
  void join(std::string const &channel);
  void part(std::string const &channel);
  bool isJoined(std::string const &channel) const;

  bool receive();
  bool makeRequest();
  Request const &getRequest() const;

  static const int kMaxChannel;

 private:
  bool               auth_;
  std::string        password_;
  int                sock_;
  struct sockaddr_in addr_;

  std::string nick_;
  std::string user_;
  std::string real_;
  std::string host_;

  std::string buffer_;
  bool        can_write_;

  UMstring_bool joined_channel_;

  Request request_;
};

} // namespace irc

#endif // IRCSERV_CLIENT_H_
