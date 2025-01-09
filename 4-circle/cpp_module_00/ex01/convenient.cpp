/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convenient.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 22:13:00 by tkong             #+#    #+#             */
/*   Updated: 2023/02/11 02:47:02 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convenient.hpp"

void getString(const std::string& prompt, std::string& str) {
	while (true) {
		std::cout << prompt;
		std::getline(std::cin, str);
		if (str.size()) {
			break;
		}
	}
}
