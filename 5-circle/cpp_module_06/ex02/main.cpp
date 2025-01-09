/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 05:14:10 by tkong             #+#    #+#             */
/*   Updated: 2023/02/27 22:00:45 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <random>

int _rand(int mn, int mx) {
	static std::mt19937 gnt((std::random_device())());
	return (std::uniform_int_distribution<int>(mn, mx))(gnt);
}
Base *generate() {
	switch (_rand(0, 2)) {
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return NULL;
	}
}
void identify(Base *p) {
	if (dynamic_cast<A *>(p)) {
		std::cout << "A";
		return;
	}
	if (dynamic_cast<B *>(p)) {
		std::cout << "B";
		return;
	}
	if (dynamic_cast<C *>(p)) {
		std::cout << "C";
		return;
	}
}
void identify(Base &p) {
	try {
		(void) dynamic_cast<A &>(p);
		std::cout << "A";
		return;
	} catch (...) {}
	try {
		(void) dynamic_cast<B &>(p);
		std::cout << "B";
		return;
	} catch (...) {}
	try {
		(void) dynamic_cast<C &>(p);
		std::cout << "C";
		return;
	} catch (...) {}
}

int main() {
	for (int i = 0; i < 10; ++i) {
		Base *ptr = generate();
		if (ptr) {
			identify(ptr);
			identify(*ptr);
			std::cout << '\n';
			delete ptr;
		}
	}
}
