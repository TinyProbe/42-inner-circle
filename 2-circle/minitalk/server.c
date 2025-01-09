/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:37:08 by tkong             #+#    #+#             */
/*   Updated: 2022/09/21 15:37:09 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_string	g_msg;

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	g_msg.shift = 8;
	while (1)
		pause();
	return (0);
}
