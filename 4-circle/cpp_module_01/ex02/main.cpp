/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:51:36 by tkong             #+#    #+#             */
/*   Updated: 2023/02/11 23:12:12 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

int main() {
	std::string hi("HI THIS IS BRAIN");
	std::string* pstr = &hi;
	std::string& rstr = hi;
	std::ostringstream oss[3];

	oss[0] << std::hex << &hi;
	oss[1] << std::hex << pstr;
	oss[2] << std::hex << &rstr;
	std::cout << oss[0].str() << '\n';
	std::cout << oss[1].str() << '\n';
	std::cout << oss[2].str() << '\n';
	std::cout << hi << '\n';
	std::cout << *pstr << '\n';
	std::cout << rstr << '\n';
}
