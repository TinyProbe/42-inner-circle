/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:15:38 by tkong             #+#    #+#             */
/*   Updated: 2023/02/22 03:28:11 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
	std::string name;
	Weapon& wpn;

	HumanA();

public:
	HumanA(const std::string& name, Weapon& wpn);
	~HumanA();

	void attack() const;

};

#endif
