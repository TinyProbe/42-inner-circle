/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:37:06 by tkong             #+#    #+#             */
/*   Updated: 2022/09/21 19:12:22 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	getsig(int bit);

int	send(pid_t pid, const char *s)
{
	int	shift;
	int	len;
	int	i;

	len = ft_strlen(s);
	i = -1;
	while (++i <= len)
	{
		shift = 8;
		while (shift--)
			if ((usleep(100) || 1) && kill(pid, getsig(s[i] & (1 << shift))))
				return (-1);
	}
	return (0);
}

static int	getsig(int bit)
{
	if (bit)
		return (SIGUSR2);
	return (SIGUSR1);
}
