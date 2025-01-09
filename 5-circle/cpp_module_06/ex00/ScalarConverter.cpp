/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:07:22 by tkong             #+#    #+#             */
/*   Updated: 2023/07/28 09:57:53 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <sstream>
#include <float.h>

static void delback(std::string &s) {
	if (s.size() && s.back() == 'f') {
		s.pop_back();
	}
	while (s.size()) {
		if (s.back() == '0') {
			s.pop_back();
		} else {
			break;
		}
	}
}

static int _cmp(std::string l, std::string r) {
	const int SAME = 0, BIG_L = 1, BIG_R = -1;
	bool pst_l = true, pst_r = true;
	if (l[0] == '-') { l.erase(l.begin()); pst_l = false; }
	if (r[0] == '-') { r.erase(r.begin()); pst_r = false; }
	if (pst_l && pst_r) {
		if (l.size() > r.size()) { return BIG_L; }
		else if (l.size() < r.size()) { return BIG_R; }
		else if (l.size() == r.size()) {
			for (int i = 0; i < (int) l.size(); ++i) {
				if (l[i] > r[i]) { return BIG_L; }
				else if (l[i] < r[i]) { return BIG_R; }
			}
			return SAME;
		}
	} else if (!pst_l && !pst_r) {
		if (l.size() > r.size()) { return BIG_R; }
		else if (l.size() < r.size()) { return BIG_L; }
		else if (l.size() == r.size()) {
			for (int i = 0; i < (int) l.size(); ++i) {
				if (l[i] > r[i]) { return BIG_R; }
				else if (l[i] < r[i]) { return BIG_L; }
			}
			return SAME;
		}
	} else if (pst_l && !pst_r) {
		return BIG_L;
	} else if (!pst_l && pst_r) {
		return BIG_R;
	}
	return 0;
}

static int _flt_cmp(std::string l, std::string r) {
	const int SAME = 0, BIG_L = 1, BIG_R = -1;
	size_t lp = l.find_first_of('.');
	size_t rp = r.find_first_of('.');
	std::string ll = l.substr(0, lp);
	std::string lr = l.substr(lp + 1, l.size() - (lp + 1));
	std::string rl = r.substr(0, rp);
	std::string rr = r.substr(rp + 1, r.size() - (rp + 1));
	switch (_cmp(ll, rl)) {
		case BIG_R: return BIG_R;
		case BIG_L: return BIG_L;
		case SAME: {
			if (lr < rr) {
				if (l.front() == '-') {
					return BIG_L;
				} else {
					return BIG_R;
				}
			} else if (lr > rr) {
				if (l.front() == '-') {
					return BIG_R;
				} else {
					return BIG_L;
				}
			} else {
				return SAME;
			}
		} break;
		default: break;
	}
	return 0;
}

int ScalarConverter::detectType(std::string &arg) {
	int integer       = 0;
	int float_point   = 0;
	int float_sign    = 0;
	int pp            = -1;
	int mm            = -1;
	int fp            = -1;
	int fs            = -1;
	bool error        = false;
	bool inff         = (arg == "inff" || arg == "-inff" || arg == "+inff");
	bool inf          = (arg == "inf"  || arg == "-inf"  || arg == "+inf");
	bool nanf         = (arg == "nanf");
	bool nan          = (arg == "nan");
	if (inff || nanf) {
		arg.pop_back();
		return FLT__;
	} else if (inf || nan) {
		return DBL__;
	}
	std::string allow = "+-.f";
	for (int i = 0; i < (int) arg.size(); ++i) {
		integer     += (std::isdigit(arg[i]) ?         1 : 0);
		float_point += (arg[i] == '.'        ? fp = i, 1 : 0);
		float_sign  += (arg[i] == 'f'        ? fs = i, 1 : 0);
		pp           = (arg[i] == '+'        ?         i : pp);
		mm           = (arg[i] == '-'        ?         i : mm);
		error = (!std::isdigit(arg[i]) && allow.find_first_of(arg[i]) == std::string::npos
			? true : error);
	}
	int type = ERR__;
	type = (arg.size() == 1ul                           ? CHR__ : type);
	type = (integer                                     ? INT__ : type);
	type = (integer && float_point                      ? DBL__ : type);
	type = (integer && float_point && float_sign        ? FLT__ : type);
	type = (arg.size() != 1ul && error                  ? ERR__ : type);
	type = (type != CHR__ && !float_point && float_sign ? ERR__ : type);
	type = (float_point > 1 || float_sign > 1           ? ERR__ : type);
	type = (pp > 0          || mm > 0                   ? ERR__ : type);
	type = ((type == FLT__ || type == DBL__) && fp == 0 ? ERR__ : type);
	type = (type == FLT__ && fs != (long)arg.size()-1   ? ERR__ : type);
	std::string int_min, int_max, flt_min, flt_max, dbl_min, dbl_max;
	std::stringstream ss;
	ss << std::fixed
		<< INT_MIN << ' ' << INT_MAX << ' '
		<< -FLT_MAX << ' ' << FLT_MAX << ' '
		<< -DBL_MAX << ' ' << DBL_MAX;
	ss >> int_min >> int_max >> flt_min >> flt_max >> dbl_min >> dbl_max;
	switch (type) {
		case INT__:
			type = (arg[0] == '-' && _cmp(arg, int_min) == -1 ? ERR__ : type);
			type = (arg[0] != '-' && _cmp(arg, int_max) ==  1 ? ERR__ : type);
			break;
		case FLT__:
			delback(arg);
			delback(flt_max);
			type = (arg[0] == '-' && _flt_cmp(arg, flt_min) == -1 ? ERR__ : type);
			type = (arg[0] != '-' && _flt_cmp(arg, flt_max) ==  1 ? ERR__ : type);
			break;
		case DBL__:
			delback(arg);
			delback(dbl_max);
			type = (arg[0] == '-' && _flt_cmp(arg, dbl_min) == -1 ? ERR__ : type);
			type = (arg[0] != '-' && _flt_cmp(arg, dbl_max) ==  1 ? ERR__ : type);
			break;
		default: break;
	}
	return type;
}
