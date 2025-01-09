/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:15:40 by tkong             #+#    #+#             */
/*   Updated: 2023/02/24 11:48:31 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB() :
	name(), wpn() {}
HumanB::HumanB(const std::string& name) :
	name(name), wpn() {}
HumanB::~HumanB() {}

void HumanB::attack() const {
	std::cout << (this->wpn ? this->wpn->getType() : "(null)") << '\n';
}
void HumanB::setWeapon(Weapon& wpn) { this->wpn = &wpn; }
