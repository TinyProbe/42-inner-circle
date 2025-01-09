/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:00:47 by tkong             #+#    #+#             */
/*   Updated: 2023/02/24 11:53:28 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int main(int ac, char** av) {
	if (ac != 4) {
		return 1;
	}
	std::string file(av[1]);
	std::string s1(av[2]);
	std::string s2(av[3]);
	std::ifstream ifs(file);
	if (!ifs.is_open()) {
		return 1;
	}
	std::ofstream ofs(file + std::string(".replace"));
	if (!ofs.is_open()) {
		ifs.close();
		return 1;
	}
	std::string src;
	std::string dst;
	while (getline(ifs, dst)) {
		src += (dst + '\n');
	}
	dst.clear();
	int l = 0, r = 0;
	while (true) {
		r = src.find(s1, l);
		if ((size_t) r == src.npos) {
			dst += src.substr(l);
			break;
		}
		dst += src.substr(l, r - l);
		dst += s2;
		l = r + s1.size();
	}
	ofs.write(dst.c_str(), dst.size());
	ifs.close();
	ofs.close();
}
