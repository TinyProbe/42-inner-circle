/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 05:55:10 by tkong             #+#    #+#             */
/*   Updated: 2023/02/14 04:06:40 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool Point::bsp(Point const a, Point const b, Point const c, Point const point) {
	bool abac = Point::getIsCenter(a, b, c, point);
	bool bcba = Point::getIsCenter(b, c, a, point);
	bool cacb = Point::getIsCenter(c, a, b, point);
	return (abac && bcba && cacb);
}
