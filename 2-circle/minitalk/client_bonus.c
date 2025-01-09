/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:45:07 by tkong             #+#    #+#             */
/*   Updated: 2022/09/22 17:02:57 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_string	g_msg;

static void	extract(char **argv);

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (-1);
	extract(argv);
	send(g_msg.pid_you, &(g_msg.len_me), 1);
	send(g_msg.pid_you, g_msg.me, g_msg.len_me);
	send(g_msg.pid_you, argv[2], ft_strlen(argv[2]) + 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	g_msg.shift = 8;
	while (1)
		pause();
	return (0);
}

static void	extract(char **argv)
{
	char	*tmp;

	g_msg.who = CLIENT;
	g_msg.pid_me = getpid();
	tmp = ft_itoa(g_msg.pid_me);
	g_msg.len_me = ft_strlen(tmp);
	ft_memcpy(g_msg.me, tmp, g_msg.len_me);
	g_msg.pid_you = ft_atoi(argv[1]);
	free(tmp);
}
