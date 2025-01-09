/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 04:23:39 by tkong             #+#    #+#             */
/*   Updated: 2023/02/18 05:04:52 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}
Data *Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}
