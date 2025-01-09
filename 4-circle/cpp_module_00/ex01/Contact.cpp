/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:23:00 by tkong             #+#    #+#             */
/*   Updated: 2023/02/11 03:17:02 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}
const std::string& Contact::getFirstName() const { return firstname; }
const std::string& Contact::getLastName() const { return lastname; }
const std::string& Contact::getNickName() const { return nickname; }
const std::string& Contact::getPhoneNum() const { return phonenum; }
const std::string& Contact::getSecret() const { return secret; }
void Contact::setFirstName(const std::string& s) { firstname = s; }
void Contact::setLastName(const std::string& s) { lastname = s; }
void Contact::setNickName(const std::string& s) { nickname = s; }
void Contact::setPhoneNum(const std::string& s) { phonenum = s; }
void Contact::setSecret(const std::string& s) { secret = s; }
