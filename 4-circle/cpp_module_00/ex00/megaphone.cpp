/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:42:17 by tkong             #+#    #+#             */
/*   Updated: 2023/02/10 18:59:22 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char** av) {
	for (int i = 1; i < ac; ++i) {
		for (int j = 0; av[i][j]; ++j) {
			std::cout << (char) toupper(av[i][j]);
		}
	}
	if (!(ac > 1 && av[1][0])) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
}
