/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:50:05 by tkong             #+#    #+#             */
/*   Updated: 2023/02/22 03:37:18 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	{
		Zombie* zom;
		zom = Zombie::newZombie("Zomb1");
		zom->Announce();
		delete zom;
		zom = Zombie::newZombie("Zomb2");
		zom->Announce();
		delete zom;
		zom = Zombie::newZombie("Zomb3");
		zom->Announce();
		delete zom;
		zom = Zombie::newZombie("Zomb4");
		zom->Announce();
		delete zom;
		zom = Zombie::newZombie("Zomb5");
		zom->Announce();
		delete zom;
	}
	{
		Zombie::randomChump("PrettyZomb1");
		Zombie::randomChump("PrettyZomb2");
		Zombie::randomChump("PrettyZomb3");
		Zombie::randomChump("PrettyZomb4");
		Zombie::randomChump("PrettyZomb5");
		Zombie::randomChump("UnPrettyZomb1");
		Zombie::randomChump("UnprettyZomb2");
		Zombie::randomChump("UnPrettyZomb3");
		Zombie::randomChump("UnPrettyZomb4");
		Zombie::randomChump("UnPrettyZomb5");
	}
}
