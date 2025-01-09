/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 04:23:38 by tkong             #+#    #+#             */
/*   Updated: 2023/02/18 05:03:53 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data data;
	data.i = 10;
	data.f = 12.12f;

	uintptr_t p1 = Serializer::serialize(&data);
	Data *p2 = Serializer::deserialize(p1);
	if (&data == p2) {
		std::cout << "same\n";
	} else {
		std::cout << "unsame\n";
	}
	std::cout << data.i << ' ' << data.f << '\n';
	std::cout << p2->i << ' ' << p2->f << '\n';
}
