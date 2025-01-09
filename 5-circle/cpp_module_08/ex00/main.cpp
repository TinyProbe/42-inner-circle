/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:29:24 by tkong             #+#    #+#             */
/*   Updated: 2023/07/31 09:40:02 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main() {
	std::vector<int> v(10);
	for (size_t i=0; i<v.size(); ++i) { v[i] = i; }
	for (size_t i=0; i<v.size()+5; ++i) {
		std::vector<int>::iterator it = easyfind(v, i);
		if (it != v.end()) {
			std::cout << *it << '\n';
		} else {
			std::cout << "Not exist\n";
		}
	}
	std::list<int> l;
	for (size_t i=0; i<10; ++i) { l.push_back(i); }
	for (size_t i=0; i<15; ++i) {
		std::list<int>::iterator it = easyfind(l, i);
		if (it != l.end()) {
			std::cout << *it << '\n';
		} else {
			std::cout << "Not exist\n";
		}
	}
}
