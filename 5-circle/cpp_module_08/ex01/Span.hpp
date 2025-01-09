/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:02:32 by tkong             #+#    #+#             */
/*   Updated: 2023/07/31 09:48:20 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
	const size_t N;
	std::vector<long> v;

private:
	virtual size_t findSpan(bool isLong) const;

public:
	Span();
	Span(const Span &rhs);
	Span(size_t N);
	virtual ~Span();
	virtual Span &operator=(const Span &rhs);

	virtual void addNumber(long n);
	virtual void addNumbers(std::vector<long>::iterator b, std::vector<long>::iterator e);
	virtual size_t shortestSpan() const;
	virtual size_t longestSpan() const;
	virtual std::vector<long>::iterator begin();
	virtual std::vector<long>::iterator end();

};

#endif
