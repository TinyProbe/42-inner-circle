/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:50:01 by tkong             #+#    #+#             */
/*   Updated: 2023/02/22 03:14:01 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void Announce(void);

	static Zombie* zombieHorde(int N, std::string name);

};

#endif
