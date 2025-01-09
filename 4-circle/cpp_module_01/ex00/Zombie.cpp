/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:50:02 by tkong             #+#    #+#             */
/*   Updated: 2023/02/22 03:23:38 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie() : name() {}
Zombie::Zombie(std::string name) : name(name) {}
Zombie::~Zombie() {
	std::cout << name << ": Destructor called\n";
}

void Zombie::Announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}
