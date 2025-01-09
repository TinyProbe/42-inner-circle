/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:24:36 by tkong             #+#    #+#             */
/*   Updated: 2023/02/16 20:42:30 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:
	ScavTrap();
	ScavTrap(const ScavTrap& rhs);
	ScavTrap(const std::string& name);
	virtual ~ScavTrap();
	virtual ScavTrap& operator=(const ScavTrap& rhs);

	virtual void attack(const std::string& target);
	virtual void guardGate() const;

};

#endif
