/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:52:04 by tkong             #+#    #+#             */
/*   Updated: 2023/02/24 12:08:35 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char** av) {
	if (ac != 2) {
		return 1;
	}
	Harl h;
	std::string arg(av[1]);
	int sel = 0;
	sel = (arg == "debug" ? 1 : sel);
	sel = (arg == "info" ? 2 : sel);
	sel = (arg == "warning" ? 3 : sel);
	sel = (arg == "error" ? 4 : sel);
	switch (sel) {
		case 1: h.complain(DEBUG__);
		case 2: h.complain(INFO__);
		case 3: h.complain(WARN__);
		case 4: h.complain(ERROR__);
			break;
		default:
			std::cout << "No one here that same input argument.\n";
	}
}
