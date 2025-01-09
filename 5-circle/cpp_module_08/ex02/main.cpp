/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:04:09 by tkong             #+#    #+#             */
/*   Updated: 2023/07/30 14:54:14 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int main()
{
	MutantStack<int> muts;
	muts.push(5);
	muts.push(17);
	std::cout << muts.top() << std::endl;
	muts.pop();
	std::cout << "size: " << muts.size() << std::endl;
	muts.push(3);
	muts.push(5);
	muts.push(737);
	for (int i=0; i<1000; ++i) { muts.push(i); }
	std::cout << "size: " << muts.size() << std::endl;
	for (int i=0; i<990; ++i) { muts.pop(); }
	std::cout << "size: " << muts.size() << std::endl;
	muts.push(0);
	MutantStack<int>::iterator it = muts.begin();
	MutantStack<int>::iterator it2 = muts.end();
	++it;
	--it;
	std::cout << "muts: ";
	while (it != it2) {
		std::cout << *it << ' ';
		++it;
	}
	std::cout << '\n';
	std::stack<int> s(muts);
	std::cout << "s:    ";
	while (!s.empty()) {
		std::cout << s.top() << ' ';
		s.pop();
	}
	std::cout << '\n';
}
