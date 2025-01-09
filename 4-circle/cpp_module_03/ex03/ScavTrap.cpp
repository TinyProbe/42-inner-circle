/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:24:37 by tkong             #+#    #+#             */
/*   Updated: 2023/02/24 04:47:36 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap Default constructor called\n";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attDamage = 20;
}
ScavTrap::ScavTrap(const ScavTrap& rhs) {
	std::cout << "ScavTrap Copy constructor called\n";
	*this = rhs;
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap Name constructor called\n";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attDamage = 20;
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called\n";
}
ScavTrap& ScavTrap::operator=(const ScavTrap& rhs) {
	std::cout << "ScavTrap Copy operator called\n";
	if (this == &rhs) {
		return *this;
	}
	dynamic_cast<ClapTrap&>(*this) = dynamic_cast<const ClapTrap&>(rhs);
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (this->hitPoint > 0 && this->energyPoint >= 1) {
		std::cout << "ScavTrap " << this->name << " attacks " << target
			<< ", causing " << this->attDamage << " points of damage!\n";
		this->energyPoint--;
	} else {
		std::cout << "ScavTrap " << this->name << " can't attack anymore\n";
	}
}

void ScavTrap::guardGate() const {
	std::cout << "ScavTrap " << this->name
		<< " is now in Gate keeper mode\n";
}
