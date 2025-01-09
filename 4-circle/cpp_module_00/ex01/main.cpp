/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:41:16 by tkong             #+#    #+#             */
/*   Updated: 2023/02/11 02:27:40 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "convenient.hpp"
#include "PhoneBook.hpp"

int main() {
	PhoneBook pb;
	std::string cmd;

	while (true) {
		getString("Input command[add/search/exit]: ", cmd);
		if (cmd == "add") {
			pb.add();
		} else if (cmd == "search") {
			pb.search();
		} else if (cmd == "exit") {
			break;
		}
		std::cout << '\n';
	}
}
