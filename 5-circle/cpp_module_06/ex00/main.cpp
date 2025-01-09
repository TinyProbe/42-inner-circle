/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:43:19 by tkong             #+#    #+#             */
/*   Updated: 2023/07/28 10:23:17 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <float.h>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "error: too little/many arguments\n";
		return 1;
	} else if (strlen(av[1]) == 0) {
		std::cout << "error: argument cannot be empty\n";
		return 2;
	}
	std::string arg(av[1]);
	int type = ScalarConverter::detectType(arg);
	if (type == ERR__) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: impossible\n";
		std::cout << "double: impossible\n";
		return 0;
	}
	char   c = (type == CHR__ ? arg[0]                                : 0);
	int    i = (type == INT__ ? ScalarConverter::convert<int>(arg)    : 0);
	float  f = (type == FLT__ ? ScalarConverter::convert<float>(arg)  : 0);
	double d = (type == DBL__ ? ScalarConverter::convert<double>(arg) : 0);
	int ctype = CHR__, itype = INT__, ftype = FLT__;
	switch (type) {
		case CHR__:
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case INT__: {
			int char_min = (int)CHAR_MIN, char_max = (int)CHAR_MAX;
			if (char_min > i || char_max < i) {
				ctype = ERR__;
			} else if (!std::isprint(i)) {
				ctype = NONE__;
			}
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
		} break;
		case FLT__: {
			float char_min = (float)CHAR_MIN, char_max = (float)CHAR_MAX;
			float int_min = (float)INT_MIN, int_max = (float)INT_MAX;
			if (f > int_max || f < int_min || arg == "nan") {
				ctype = ERR__;
				itype = ERR__;
			} else if (char_min > f || char_max < f) {
				ctype = ERR__;
			} else if (!std::isprint(f)) {
				ctype = NONE__;
			}
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
		} break;
		case DBL__: {
			double char_min = (double)CHAR_MIN, char_max = (double)CHAR_MAX;
			double int_min = (double)INT_MIN, int_max = (double)INT_MAX;
			double flt_max = (double)FLT_MAX;
			double flt_min = -flt_max;
			if (d > flt_max || d < flt_min) {
				if (arg.find("inf") == std::string::npos) {
					ftype = ERR__;
				}
				ctype = ERR__;
				itype = ERR__;
			} else if (d > int_max || d < int_min || arg == "nan") {
				ctype = ERR__;
				itype = ERR__;
			} else if (char_min > d || char_max < d) {
				ctype = ERR__;
			} else if (!std::isprint(d)) {
				ctype = NONE__;
			}
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
		} break;
		default: break;
	}
	std::cout << "char: "   << ScalarConverter::format(c, ctype) << '\n';
	std::cout << "int: "    << ScalarConverter::format(i, itype) << '\n';
	std::cout << "float: "  << ScalarConverter::format(f, ftype) << '\n';
	std::cout << "double: " << ScalarConverter::format(d, DBL__) << '\n';
}

