/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:45:13 by tkong             #+#    #+#             */
/*   Updated: 2022/09/22 16:21:53 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_string	g_msg;

static void	extract(void);

int	main(void)
{
	extract();
	write(1, g_msg.me, g_msg.len_me);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	g_msg.shift = 8;
	while (1)
		pause();
	return (0);
}

static void	extract(void)
{
	char	*tmp;

	g_msg.who = SERVER;
	g_msg.pid_me = getpid();
	tmp = ft_itoa(g_msg.pid_me);
	g_msg.len_me = ft_strlen(tmp);
	ft_memcpy(g_msg.me, tmp, g_msg.len_me);
	free(tmp);
}
