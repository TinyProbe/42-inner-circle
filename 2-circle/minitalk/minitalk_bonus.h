/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:46:41 by tkong             #+#    #+#             */
/*   Updated: 2022/09/22 15:04:45 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "libft/libft.h"

# define MAX_LEN	1000000
# define MAX_PID	100
# define SERVER		1
# define CLIENT		2

typedef struct s_string
{
	int		who;
	pid_t	pid_me;
	pid_t	pid_you;
	char	len_me;
	char	len_you;
	char	me[MAX_PID];
	char	you[MAX_PID];
	char	str[MAX_LEN];
	int		len;
	int		shift;
}	t_string;

extern t_string	g_msg;

int		send(pid_t pid, const char *s, int n);
void	handler(int signum);

#endif
