/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:39:56 by tkong             #+#    #+#             */
/*   Updated: 2023/02/16 20:43:55 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap();
	FragTrap(const FragTrap& rhs);
	FragTrap(const std::string& name);
	virtual ~FragTrap();
	virtual FragTrap& operator=(const FragTrap& rhs);

	virtual void highFivesGuys(void) const;

};

#endif
