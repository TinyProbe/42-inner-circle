/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:15:36 by tkong             #+#    #+#             */
/*   Updated: 2023/02/24 11:49:35 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
	std::string type;

public:
	Weapon();
	Weapon(const std::string& type);
	~Weapon();

	const std::string& getType() const;
	void setType(const std::string& type);

};

#endif
