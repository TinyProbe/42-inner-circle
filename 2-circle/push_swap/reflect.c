/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:52:04 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:54:33 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwap.h"

static void	calc(t_ds *store, int *dir, int *dist);
static void	common_rotate(t_ds *store, int *dir, int *dist);
static void	indiv_rotate(t_ds *store, int *dir, int *dist);

void	reflect(t_ds *store)
{
	int	dir[2];
	int	dist[2];

	calc(store, dir, dist);
	common_rotate(store, dir, dist);
	indiv_rotate(store, dir, dist);
}

static void	calc(t_ds *store, int *dir, int *dist)
{
	dir[0] = 1;
	dist[0] = store->dist_a;
	dir[1] = 1;
	dist[1] = store->dist_b;
	if (store->dist_a > store->len_a - store->dist_a)
	{
		dir[0] = -dir[0];
		dist[0] = store->len_a - dist[0];
	}
	if (store->dist_b > store->len_b - store->dist_b)
	{
		dir[1] = -dir[1];
		dist[1] = store->len_b - dist[1];
	}
}

static void	common_rotate(t_ds *store, int *dir, int *dist)
{
	int	tmp;

	if (dir[0] == dir[1])
	{
		tmp = _min(dist[0], dist[1]);
		dist[0] -= tmp;
		dist[1] -= tmp;
		if (dir[0] == 1)
			while (tmp--)
				rotate_r(store);
		else
			while (tmp--)
				rerotate_r(store);
	}
}

static void	indiv_rotate(t_ds *store, int *dir, int *dist)
{
	if (dir[0] == 1)
		while (dist[0]--)
			rotate_a(store);
	else
		while (dist[0]--)
			rerotate_a(store);
	if (dir[1] == 1)
		while (dist[1]--)
			rotate_b(store);
	else
		while (dist[1]--)
			rerotate_b(store);
}
