/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 06:57:19 by tkong             #+#    #+#             */
/*   Updated: 2023/08/01 10:52:39 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

#define LENGTH 5

void add(int &a) { a += 10; }
void attach(std::string &a) { a += "Hello"; }
template <class T> void print(const T &a) { std::cout << a << ", "; }

int main() {
	{
		int arr[LENGTH] = {};
		::iter(arr, LENGTH, print<int>); std::cout << '\n';
		::iter(arr, LENGTH, add);
		::iter(arr, LENGTH, print<int>); std::cout << '\n';
	}
	{
		std::string arr[LENGTH] = {};
		::iter(arr, LENGTH, print<std::string>); std::cout << '\n';
		::iter(arr, LENGTH, attach);
		::iter(arr, LENGTH, print<std::string>); std::cout << '\n';
	}
}
