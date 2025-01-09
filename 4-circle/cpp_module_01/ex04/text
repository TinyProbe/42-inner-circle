/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 02:00:47 by tkong             #+#    #+#             */
/*   Updated: 2023/02/12 03:17:54 by tkong            ###   ########.fr       */
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
	std::string src;
	std::string dst;
	while (!ifs.eof()) {
		src += ifs.get();
	}
	src.resize(src.size() - 2);
	for (int i = 0; i < (int) src.size(); ) {
		bool same = true;
		if ((int) src.size() - i >= (int) s1.size()) {
			for (int j = i; j < i + (int) s1.size(); ++j) {
				if (src[j] != s1[j - i]) {
					same = false;
					break;
				}
			}
		} else {
			same = false;
		}
		if (same) {
			dst += s2;
			i += (int) s1.size();
		} else {
			dst += src[i++];
		}
	}
	ofs.write(dst.c_str(), dst.size());
	ifs.close();
	ofs.close();
}
