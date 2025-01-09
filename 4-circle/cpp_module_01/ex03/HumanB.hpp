/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:15:39 by tkong             #+#    #+#             */
/*   Updated: 2023/02/22 03:28:30 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
	std::string name;
	Weapon* wpn;

public:
	HumanB();
	HumanB(const std::string& name);
	~HumanB();

	void attack() const;
	void setWeapon(Weapon& wpn);

};

#endif
