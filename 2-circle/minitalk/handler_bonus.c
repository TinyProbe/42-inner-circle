/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:45:10 by tkong             #+#    #+#             */
/*   Updated: 2022/09/22 16:49:14 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	quarter(void);
static void	reply(void);

void	handler(int signum)
{
	g_msg.shift--;
	if (signum == SIGUSR2)
		g_msg.str[g_msg.len] |= (1 << g_msg.shift);
	if (g_msg.shift == 0)
		quarter();
}

static void	quarter(void)
{
	g_msg.shift = 8;
	if (g_msg.str[g_msg.len++] == 0)
	{
		write(1, g_msg.str + (g_msg.str[0] + 1),
			g_msg.len - (g_msg.str[0] + 2));
		write(1, "\n", 1);
		if (g_msg.who == SERVER)
			reply();
		else
			exit(0);
		g_msg.len = 0;
	}
	g_msg.str[g_msg.len] = 0;
}

static void	reply(void)
{
	g_msg.len_you = g_msg.str[0];
	ft_memcpy(g_msg.you, g_msg.str + 1, g_msg.len_you);
	g_msg.you[(int) g_msg.len_you] = '\0';
	g_msg.pid_you = ft_atoi(g_msg.you);
	send(g_msg.pid_you, &(g_msg.len_me), 1);
	send(g_msg.pid_you, g_msg.me, g_msg.len_me);
	send(g_msg.pid_you, g_msg.str + (g_msg.len_you + 1),
		g_msg.len - (g_msg.len_you + 1));
}
