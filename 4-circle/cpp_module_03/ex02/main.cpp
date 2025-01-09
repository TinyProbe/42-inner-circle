/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:34:34 by tkong             #+#    #+#             */
/*   Updated: 2023/02/14 22:09:28 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
	FragTrap a("goodguy");
	a.attack("badguy");
	a.takeDamage(30);
	a.beRepaired(10);
	a.highFivesGuys();
	a = FragTrap("badguy");
	a.attack("goodguy");
	a.takeDamage(40);
	a.beRepaired(20);
	a.highFivesGuys();
}
