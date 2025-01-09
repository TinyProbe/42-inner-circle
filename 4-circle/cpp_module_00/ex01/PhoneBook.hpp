/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:22:58 by tkong             #+#    #+#             */
/*   Updated: 2023/02/11 14:28:58 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "convenient.hpp"
#include "Contact.hpp"

#define MAX_CONTACT 8
#define COLUMN_WID 10

class PhoneBook {
	Contact ctts[MAX_CONTACT];
	int size;

	static void printList(const Contact*const& ctts, int size, int wid);
	static void printField(const std::string& str, int wid);
	static void printContact(const Contact& ctt);
public:
	PhoneBook();
	~PhoneBook();
	void add();
	void search() const;

};

#endif
