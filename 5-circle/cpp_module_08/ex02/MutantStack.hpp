/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 23:04:10 by tkong             #+#    #+#             */
/*   Updated: 2023/07/31 10:14:58 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <list>

template <class T>
class MutantStack : public std::stack<T, std::vector<T> > {

public:
	typedef typename MutantStack::container_type			container_type;
	typedef typename container_type::value_type				value_type;
	typedef typename container_type::allocator_type			allocator_type;
	typedef typename container_type::reference				reference;
	typedef typename container_type::const_reference		const_reference;
	typedef typename container_type::size_type				size_type;
	typedef typename container_type::difference_type		difference_type;
	typedef typename container_type::pointer				pointer;
	typedef typename container_type::const_pointer			const_pointer;
	typedef typename container_type::iterator				iterator;
	typedef typename container_type::const_iterator			const_iterator;
	typedef typename container_type::reverse_iterator		reverse_iterator;
	typedef typename container_type::const_reverse_iterator	const_reverse_iterator;

public:
	MutantStack();
	MutantStack(const MutantStack &rhs);
	virtual ~MutantStack();
	virtual MutantStack &operator=(const MutantStack &rhs);
	virtual operator std::stack<T>() const;

	iterator               begin()        ;
	const_iterator         begin()   const;
	iterator               end()          ;
	const_iterator         end()     const;
	reverse_iterator       rbegin()       ;
	const_reverse_iterator rbegin()  const;
	reverse_iterator       rend()         ;
	const_reverse_iterator rend()    const;
	const_iterator         cbegin()  const;
	const_iterator         cend()    const;
	const_reverse_iterator crbegin() const;
	const_reverse_iterator crend()   const;

};

#include "MutantStack.tpp"

#endif
