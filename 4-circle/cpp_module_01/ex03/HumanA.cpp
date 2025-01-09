/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:15:38 by tkong             #+#    #+#             */
/*   Updated: 2023/02/24 11:49:04 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& wpn) :
	name(name), wpn(wpn) {}
HumanA::~HumanA() {}

void HumanA::attack() const {
	std::cout << this->wpn.getType() << '\n';
}
