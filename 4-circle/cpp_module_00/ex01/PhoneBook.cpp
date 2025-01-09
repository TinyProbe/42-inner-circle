/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:22:59 by tkong             #+#    #+#             */
/*   Updated: 2023/02/11 14:56:30 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : size() {}
PhoneBook::~PhoneBook() {}

void PhoneBook::printList(const Contact*const& ctts, int size, int wid) {
	printField("Index", wid);
	std::cout << '|';
	printField("First name", wid);
	std::cout << '|';
	printField("Last name", wid);
	std::cout << '|';
	printField("Nick name", wid);
	std::cout << '\n';
	for (int i = 0; i < std::min(MAX_CONTACT, size); ++i) {
		printField(std::to_string(i), wid);
		std::cout << '|';
		printField(ctts[i].getFirstName(), wid);
		std::cout << '|';
		printField(ctts[i].getLastName(), wid);
		std::cout << '|';
		printField(ctts[i].getNickName(), wid);
		std::cout << '\n';
	}
}

void PhoneBook::printField(const std::string& str, int wid) {
	if ((int) str.size() > wid) {
		std::cout << str.substr(0, wid - 1);
		std::cout << '.';
	} else {
		for (int i = std::max(0, wid - (int) str.size()); i--; ) {
			std::cout << ' ';
		}
		std::cout << str;
	}
}

void PhoneBook::printContact(const Contact& ctt) {
	std::cout << "First Name: " << ctt.getFirstName() << '\n';
	std::cout << "Last Name: " << ctt.getLastName() << '\n';
	std::cout << "Nick Name: " << ctt.getNickName() << '\n';
	std::cout << "Phone Number: " << ctt.getPhoneNum() << '\n';
	std::cout << "Darkest Secret: " << ctt.getSecret() << '\n';
}

void PhoneBook::add() {
	std::string str;

	getString("First name: ", str);
	ctts[size % MAX_CONTACT].setFirstName(str);
	getString("Last name: ", str);
	ctts[size % MAX_CONTACT].setLastName(str);
	getString("Nick name: ", str);
	ctts[size % MAX_CONTACT].setNickName(str);
	getString("Phone number: ", str);
	ctts[size % MAX_CONTACT].setPhoneNum(str);
	getString("Darkest Secret: ", str);
	ctts[size % MAX_CONTACT].setSecret(str);
	++size;
}

void PhoneBook::search() const {
	std::string str;
	int sel;

	if (!size) {
		std::cout << "There is no data to display.\n";
		return;
	}
	printList(ctts, size, COLUMN_WID);
	getString("Select index: ", str);
	for (int i = 0; i < (int) str.size(); ++i) {
		if (std::isdigit(str[i]) == false) {
			std::cout << "Please make sure your select that selectable choice.\n";
			return;
		}
	}
	sel = std::atoi(str.c_str());
	if (sel >= 0 && sel < std::min(MAX_CONTACT, size)) {
		printContact(ctts[sel]);
	} else {
		std::cout << "Please make sure your select that selectable choice.\n";
	}
}
