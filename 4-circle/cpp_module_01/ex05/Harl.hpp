/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:52:04 by tkong             #+#    #+#             */
/*   Updated: 2023/02/22 04:52:59 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

#define DEBUG__ "0: debug"
#define INFO__ "1: info"
#define WARN__ "2: warning"
#define ERROR__ "3: error"

class Harl {
	void (Harl::*f[4])(void);

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl();
	~Harl();

	void complain(std::string level);

};

#endif
