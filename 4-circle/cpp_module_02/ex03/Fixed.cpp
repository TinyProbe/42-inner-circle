/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:14:50 by tkong             #+#    #+#             */
/*   Updated: 2023/02/21 15:08:52 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : val() {}
Fixed::Fixed(const int& val) {
	this->val = (val << this->float_bit);
}
Fixed::Fixed(const float& val) {
	this->val = roundf(val * (1 << this->float_bit));
}
Fixed::Fixed(const Fixed& rhs) {
	*this = rhs;
}
Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& rhs) {
	if (this == &rhs) {
		return *this;
	}
	this->val = rhs.val;
	return *this;
}
bool Fixed::operator>(const Fixed& rhs) const {
	return this->getRawBits() > rhs.getRawBits();
}
bool Fixed::operator<(const Fixed& rhs) const {
	return this->getRawBits() < rhs.getRawBits();
}
bool Fixed::operator>=(const Fixed& rhs) const {
	return this->getRawBits() >= rhs.getRawBits();
}
bool Fixed::operator<=(const Fixed& rhs) const {
	return this->getRawBits() <= rhs.getRawBits();
}
bool Fixed::operator==(const Fixed& rhs) const {
	return this->getRawBits() == rhs.getRawBits();
}
bool Fixed::operator!=(const Fixed& rhs) const {
	return this->getRawBits() != rhs.getRawBits();
}
Fixed Fixed::operator+(const Fixed& rhs) const {
	return Fixed(this->toFloat() + rhs.toFloat());
}
Fixed Fixed::operator-(const Fixed& rhs) const {
	return Fixed(this->toFloat() - rhs.toFloat());
}
Fixed Fixed::operator*(const Fixed& rhs) const {
	return Fixed(this->toFloat() * rhs.toFloat());
}
Fixed Fixed::operator/(const Fixed& rhs) const {
	return Fixed(this->toFloat() / rhs.toFloat());
}
Fixed& Fixed::operator++() {
	this->val++;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++*this;
	return tmp;
}
Fixed& Fixed::operator--() {
	this->val--;
	return *this;
}
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--*this;
	return tmp;
}

int Fixed::getRawBits(void) const {
	return this->val;
}
void Fixed::setRawBits(int const raw) {
	this->val = raw;
}
int Fixed::toInt(void) const {
	return (this->val >> this->float_bit);
}
float Fixed::toFloat(void) const {
	return (float) this->val / (1 << this->float_bit);
}

Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
	if (lhs < rhs) {
		return lhs;
	}
	return rhs;
}
Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
	if (lhs > rhs) {
		return lhs;
	}
	return rhs;
}
const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
	if (lhs < rhs) {
		return lhs;
	}
	return rhs;
}
const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
	if (lhs > rhs) {
		return lhs;
	}
	return rhs;
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs) {
	return os << rhs.toFloat();
}
