/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:34:34 by tkong             #+#    #+#             */
/*   Updated: 2023/02/23 18:37:56 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	{
		ClapTrap a("goodguy");
		for (int i = 0; i < 6; ++i) {
			a.attack("badguy");
			a.beRepaired(1);
		}
	}
	{
		ClapTrap a("goodguy");
		for (int i = 0; i < 6; ++i) {
			a.attack("badguy");
			a.takeDamage(-1);
		}
	}
	ClapTrap a("goodguy");
	a.takeDamage(3);
	a.takeDamage(3);
	a.takeDamage(3);
	a.takeDamage(3);
	a.takeDamage(3);
}
