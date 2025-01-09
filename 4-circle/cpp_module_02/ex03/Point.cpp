/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:55:09 by tkong             #+#    #+#             */
/*   Updated: 2023/02/14 18:19:24 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(), y() {}
Point::Point(const float& x, const float& y) : x(x), y(y) {}
Point::Point(const Point& rhs) : x(rhs.getX()), y(rhs.getY()) {}
Point::~Point() {}
Point& Point::operator=(const Point& rhs) {
	if (this == &rhs) {
		return *this;
	}
	const_cast<Fixed&>(x) = rhs.getX();
	const_cast<Fixed&>(y) = rhs.getY();
	return *this;
}

const Fixed& Point::getX() const {
	return this->x;
}
const Fixed& Point::getY() const {
	return this->y;
}

Fixed Point::getLean(const Point& p1, const Point& p2) {
	Fixed dif_x(p2.getX() - p1.getX());
	Fixed dif_y(p2.getY() - p1.getY());
	return dif_y / dif_x;
}
bool Point::getIsCenter(const Point& b, const Point& e1, const Point& e2, const Point& p) {
	Fixed l(Point::getLean(b, e1));
	Fixed c(Point::getLean(b, p));
	Fixed r(Point::getLean(b, e2));
	bool reverse = false;
	if ((e1.getX() < b.getX() && b.getX() < e2.getX())
		|| (e1.getX() > b.getX() && b.getX() > e2.getX())) {
		reverse = true;
	}
	if (l < r) {
		return (reverse ? !(l < c && c < r) : (l < c && c < r));
	} else {
		return (reverse ? !(l > c && c > r) : (l > c && c > r));
	}
}
