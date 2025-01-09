/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 06:58:31 by tkong             #+#    #+#             */
/*   Updated: 2023/07/28 12:36:43 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
#define ITER_HPP

template <class T1, class T2>
void iter(T1 *p, int n, T2 *f) {
	for (int i=0; i<n; ++i) { f(p[i]); }
}

#endif
