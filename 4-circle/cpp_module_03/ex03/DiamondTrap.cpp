/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 22:19:56 by tkong             #+#    #+#             */
/*   Updated: 2023/02/24 08:10:39 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :
	ClapTrap(),
	ScavTrap(),
	FragTrap(),
	name("(None)")
{
	std::cout << "DiamondTrap Default constructor called\n";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attDamage = 30;
}
DiamondTrap::DiamondTrap(const DiamondTrap& rhs) {
	std::cout << "DiamondTrap Copy constructor called\n";
	*this = rhs;
}
DiamondTrap::DiamondTrap(const std::string& name) :
	ClapTrap(name),
	ScavTrap(name),
	FragTrap(name),
	name(name)
{
	std::cout << "DiamondTrap Name constructor called\n";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attDamage = 30;
}
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called\n";
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs) {
	std::cout << "DiamondTrap Copy operator called\n";
	if (this == &rhs) {
		return *this;
	}
	dynamic_cast<ScavTrap&>(*this) = dynamic_cast<const ScavTrap&>(rhs);
	dynamic_cast<FragTrap&>(*this) = dynamic_cast<const FragTrap&>(rhs);
	this->name = rhs.name;
	return *this;
}

void DiamondTrap::whoAmI() const {
	std::cout << "name: " << this->name
		<< ", ClapTrap::name: " << ClapTrap::name << '\n';
}
