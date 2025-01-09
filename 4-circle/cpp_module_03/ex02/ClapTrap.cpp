/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 04:34:36 by tkong             #+#    #+#             */
/*   Updated: 2023/02/25 11:30:15 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :
	name("(None)"),
	hitPoint(10),
	energyPoint(10),
	attDamage(0)
{
	std::cout << "ClapTrap Default constructor called\n";
}
ClapTrap::ClapTrap(const ClapTrap& rhs) {
	std::cout << "ClapTrap Copy constructor called\n";
	*this = rhs;
}
ClapTrap::ClapTrap(const std::string& name) :
	name(name),
	hitPoint(10),
	energyPoint(10),
	attDamage(0)
{
	std::cout << "ClapTrap Name constructor called\n";
}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called\n";
}
ClapTrap& ClapTrap::operator=(const ClapTrap& rhs) {
	std::cout << "ClapTrap Copy operator called\n";
	if (this == &rhs) {
		return *this;
	}
	this->name = rhs.name;
	this->hitPoint = rhs.hitPoint;
	this->energyPoint = rhs.energyPoint;
	this->attDamage = rhs.attDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->hitPoint > 0 && this->energyPoint >= 1) {
		std::cout << "ClapTrap " << this->name << " attacks " << target
			<< ", causing " << this->attDamage << " points of damage!\n";
		this->energyPoint--;
	} else {
		std::cout << "ClapTrap " << this->name << " can't attack anymore\n";
	}
}
void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hitPoint == 0) {
		std::cout << "ClapTrap " << this->name << " already dead\n";
		return;
	}
	std::cout << "ClapTrap " << this->name
		<< " take " << amount << " points of damage!\n";
	this->hitPoint -= std::min(this->hitPoint, amount);
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hitPoint > 0 && this->energyPoint >= 1) {
		std::cout << "ClapTrap " << this->name
			<< " repair itself that to " << this->hitPoint + amount
			<< " from " << this->hitPoint << '\n';
		this->hitPoint += amount;
		this->energyPoint--;
	} else {
		std::cout << "ClapTrap " << this->name << " can't repair anymore\n";
	}
}
