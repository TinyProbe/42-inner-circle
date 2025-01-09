/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:50:03 by tkong             #+#    #+#             */
/*   Updated: 2023/02/11 22:47:27 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name) {
	Zombie* zoms = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		zoms[i] = Zombie(name);
	}
	return zoms;
}
