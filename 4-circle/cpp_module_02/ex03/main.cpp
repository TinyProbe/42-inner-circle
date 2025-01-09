/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:14:49 by tkong             #+#    #+#             */
/*   Updated: 2023/02/14 04:05:35 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

int main( void ) {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			bool res1 = Point::bsp(Point(0, 0), Point(0, 12), Point(12, 6), Point(j, i));
			std::cout << (res1 ? '*' : ' ') << ' ';
		}
		std::cout << '\n';
	}
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {
			bool res1 = Point::bsp(Point(10, 2), Point(14, 16), Point(1, 10), Point(j, i));
			std::cout << (res1 ? '*' : ' ') << ' ';
		}
		std::cout << '\n';
	}
	for (int i = -10; i < 10; ++i) {
		for (int j = -10; j < 10; ++j) {
			bool res1 = Point::bsp(Point(-5, -5), Point(5, -5), Point(0, 5), Point(j, i));
			std::cout << (res1 ? '*' : ' ') << ' ';
		}
		std::cout << '\n';
	}
}
