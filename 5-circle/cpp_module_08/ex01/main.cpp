/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:02:31 by tkong             #+#    #+#             */
/*   Updated: 2023/07/31 09:48:54 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

#define MAX_LEN 10000

int main()
{
	Span sp = Span(5);
	sp.addNumber(-30);
	sp.addNumber(30);
	sp.addNumber(5);
	sp.addNumber(1);
	sp.addNumber(-1);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		sp.addNumber(30);
	} catch (const std::exception &e) {
		std::cout << e.what() << '\n';
	}

	Span sp2(MAX_LEN);
	for (int i=1; i<=MAX_LEN; ++i) {
		sp2.addNumber(i*918273%1000000);
	}
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;

	try {
		sp2.addNumbers(sp.begin(), sp.end());
	} catch (const std::exception &e) {
		std::cout << e.what() << '\n';
	}
}
