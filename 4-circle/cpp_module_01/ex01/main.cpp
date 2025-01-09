/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:50:05 by tkong             #+#    #+#             */
/*   Updated: 2023/02/22 03:22:03 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define MAX_ZOMBIE 15

void leaks() {
	system("leaks program");
}

int main() {
	Zombie* zoms = Zombie::zombieHorde(MAX_ZOMBIE, "HandsomeZomb");
	for (int i = 0; i < MAX_ZOMBIE; ++i) {
		zoms[i].Announce();
	}
	delete[] zoms;
	atexit(leaks);
}
