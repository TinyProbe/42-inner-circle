/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:34:34 by tkong             #+#    #+#             */
/*   Updated: 2023/02/15 00:43:10 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
	DiamondTrap a("goodguy");
	a.attack("badguy");
	a.takeDamage(10);
	a.beRepaired(10);
	a.guardGate();
	a.highFivesGuys();
	a.whoAmI();
	a = DiamondTrap("badguy");
	a.whoAmI();
}
