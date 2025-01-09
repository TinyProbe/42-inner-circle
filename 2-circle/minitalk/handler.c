/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:37:03 by tkong             #+#    #+#             */
/*   Updated: 2022/09/21 15:37:04 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	g_msg.shift--;
	if (signum == SIGUSR2)
		g_msg.str[g_msg.len] |= (1 << g_msg.shift);
	if (!(g_msg.shift))
	{
		g_msg.shift = 8;
		if (!(g_msg.str[g_msg.len++]))
		{
			write(1, g_msg.str, g_msg.len - 1);
			write(1, "\n", 1);
			g_msg.len = 0;
		}
		g_msg.str[g_msg.len] = 0;
	}
}
