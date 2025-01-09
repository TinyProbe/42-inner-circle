/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:02:32 by tkong             #+#    #+#             */
/*   Updated: 2023/07/31 09:48:20 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>

size_t Span::findSpan(bool isLong) const {
	if (v.size() < 2) {
		throw std::runtime_error("Not enough elements");
	}
	size_t rtn = (isLong ? 0 : UINT_MAX);
	for (size_t i=1; i<v.size(); ++i) {
		int sign = (v[i-1]<0 == v[i]<0 ? -1 : 1);
		size_t tmp = std::max(std::abs(v[i-1]), std::abs(v[i]));
		tmp += sign * std::min(std::abs(v[i-1]), std::abs(v[i]));
		rtn = (isLong ? std::max(rtn, tmp) : std::min(rtn, tmp));
	}
	return rtn;
}

Span::Span() : N() {}
Span::Span(const Span &rhs) : N() { *this = rhs; }
Span::Span(size_t N) : N(N) {}
Span::~Span() {}
Span &Span::operator=(const Span &rhs) {
	if (this == &rhs) { return *this; }
	v = rhs.v;
	const_cast<size_t &>(N) = rhs.N;
	return *this;
}

void Span::addNumber(long n) {
	if (v.size()+1 > N) {
		throw std::runtime_error("No more space");
	}
	v.push_back(n);
}
void Span::addNumbers(std::vector<long>::iterator b, std::vector<long>::iterator e) {
	if (v.size()+(e-b) > N) {
		throw std::runtime_error("No more space");
	}
	v.insert(v.end(), b, e);
}
size_t Span::shortestSpan() const { return Span::findSpan(false); }
size_t Span::longestSpan() const { return Span::findSpan(true); }
std::vector<long>::iterator Span::begin() { return v.begin(); }
std::vector<long>::iterator Span::end() { return v.end(); }
