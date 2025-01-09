/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 07:24:21 by tkong             #+#    #+#             */
/*   Updated: 2023/08/01 14:30:23 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#define MAX_VAL 750

void leaks() { system("leaks program"); }

int main() {
	{
		Array<int> arr(5);
		for (size_t i = 0; i < arr.size(); ++i) {
			std::cout << arr[i] << " -> ";
			arr[i] += i;
			std::cout << arr[i] << '\n';
		}
		try {
			std::cout << arr[10] << '\n';
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
		const Array<int> arr2 = arr;
		std::cout << arr2[2] << '\n';
	}
	{
		Array<std::string> arr(5);
		for (size_t i = 0; i < arr.size(); ++i) {
			arr[i] += "Hey!";
			std::cout << arr[i] << " -> ";
			arr[i] += " Hello World!";
			std::cout << arr[i] << '\n';
		}
		try {
			std::cout << arr[10] << '\n';
		} catch (const std::exception &e) {
			std::cout << e.what() << '\n';
		}
	}
	{
		Array<int> arr(2);
		Array<int> arr2(2);
		arr[0]=10, arr[1]=22, arr2[0]=50, arr2[1]=123;
		for (size_t i=0; i<arr.size();  ++i) { std::cout<<arr[i] <<' '; } std::cout<<'\n';
		for (size_t i=0; i<arr2.size(); ++i) { std::cout<<arr2[i]<<' '; } std::cout<<'\n';
		arr = arr2;
		for (size_t i=0; i<arr.size();  ++i) { std::cout<<arr[i] <<' '; } std::cout<<'\n';
		for (size_t i=0; i<arr2.size(); ++i) { std::cout<<arr2[i]<<' '; } std::cout<<'\n';
	}

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror;
	atexit(leaks);
}
