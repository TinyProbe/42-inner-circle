/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:37:12 by tkong             #+#    #+#             */
/*   Updated: 2022/09/21 16:39:08 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

# define MAX_LEN	1000000

typedef struct s_string
{
	char	str[MAX_LEN];
	int		len;
	int		shift;
}	t_string;

extern t_string	g_msg;

int		send(pid_t pid, const char *s);
void	handler(int signum);

#endif
