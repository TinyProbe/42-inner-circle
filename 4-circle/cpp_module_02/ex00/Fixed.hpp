/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:14:49 by tkong             #+#    #+#             */
/*   Updated: 2023/02/12 21:20:59 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	static const int float_bit = 8;
	int val;

public:
	Fixed();
	Fixed(const Fixed& rhs);
	~Fixed();
	Fixed& operator=(const Fixed& rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);

};

#endif
