/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:39:57 by tkong             #+#    #+#             */
/*   Updated: 2023/02/24 08:10:39 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap Default constructor called\n";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attDamage = 30;
}
FragTrap::FragTrap(const FragTrap& rhs) {
	std::cout << "FragTrap Copy constructor called\n";
	*this = rhs;
}
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap Name constructor called\n";
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attDamage = 30;
}
FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called\n";
}
FragTrap& FragTrap::operator=(const FragTrap& rhs) {
	std::cout << "FragTrap Copy operator called\n";
	if (this == &rhs) {
		return *this;
	}
	dynamic_cast<ClapTrap&>(*this) = dynamic_cast<const ClapTrap&>(rhs);
	return *this;
}

void FragTrap::highFivesGuys(void) const {
	std::cout << "FragTrap " << this->name
		<< " requests for a positive high five!\n";
}
