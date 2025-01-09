/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:22:59 by tkong             #+#    #+#             */
/*   Updated: 2023/02/11 14:17:07 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string phonenum;
	std::string secret;

public:
	Contact();
	~Contact();
	const std::string& getFirstName() const;
	const std::string& getLastName() const;
	const std::string& getNickName() const;
	const std::string& getPhoneNum() const;
	const std::string& getSecret() const;
	void setFirstName(const std::string& s);
	void setLastName(const std::string& s);
	void setNickName(const std::string& s);
	void setPhoneNum(const std::string& s);
	void setSecret(const std::string& s);

};

#endif
