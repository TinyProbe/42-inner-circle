/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:34:34 by tkong             #+#    #+#             */
/*   Updated: 2023/02/14 21:34:39 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap a("goodguy");
	a.attack("badguy");
	a.takeDamage(10);
	a.beRepaired(10);
	a.takeDamage(100);
	a.beRepaired(100);
	a = ScavTrap("badguy");
	a.attack("goodguy");
	a.guardGate();
}
