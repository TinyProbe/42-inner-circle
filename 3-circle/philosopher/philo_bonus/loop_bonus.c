/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 09:40:37 by tkong             #+#    #+#             */
/*   Updated: 2022/12/24 09:40:47 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	organize(t_db *db, t_i32 rtn);

void	loop(t_db *db)
{
	t_i32	rtn;

	db->num--;
	while (db->num--)
	{
		waitpid(-1, &rtn, 0);
		if (rtn)
		{
			organize(db, rtn);
			break ;
		}
	}
	sem_close(db->fork);
	sem_close(db->fork_access);
	sem_close(db->print);
	sem_unlink("/fork");
	sem_unlink("/fork_access");
	sem_unlink("/print");
}

static void	organize(t_db *db, t_i32 rtn)
{
	t_i32	idx;

	idx = -1;
	while (++idx < db->common.nop)
		kill(db->pid[idx], SIGTERM);
	while (db->num--)
		waitpid(-1, NULL, 0);
	sem_wait(db->print);
	printf("%llu %d died\n",
		ft_utom(ft_utime() - db->common.start), rtn / 256);
	sem_post(db->print);
}
