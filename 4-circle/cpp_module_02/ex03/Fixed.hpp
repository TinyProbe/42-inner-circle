/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:14:49 by tkong             #+#    #+#             */
/*   Updated: 2023/02/21 15:08:52 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	static const int float_bit = 8;
	int val;

public:
	Fixed();
	Fixed(const int& val);
	Fixed(const float& val);
	Fixed(const Fixed& rhs);
	~Fixed();
	Fixed& operator=(const Fixed& rhs);
	bool operator>(const Fixed& rhs) const;
	bool operator<(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;
	Fixed operator+(const Fixed& rhs) const;
	Fixed operator-(const Fixed& rhs) const;
	Fixed operator*(const Fixed& rhs) const;
	Fixed operator/(const Fixed& rhs) const;
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;

	static Fixed& min(Fixed& lhs, Fixed& rhs);
	static Fixed& max(Fixed& lhs, Fixed& rhs);
	static const Fixed& min(const Fixed& lhs, const Fixed& rhs);
	static const Fixed& max(const Fixed& lhs, const Fixed& rhs);

};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

#endif
