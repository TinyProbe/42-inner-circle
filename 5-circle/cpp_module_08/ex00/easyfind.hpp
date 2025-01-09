/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 09:29:25 by tkong             #+#    #+#             */
/*   Updated: 2023/07/30 13:44:26 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <class T>
typename T::iterator easyfind(T &container, int target) {
	return std::find(container.begin(), container.end(), target);
}

#endif
