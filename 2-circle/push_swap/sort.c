/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:52:05 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:56:12 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwap.h"

static void	find_optimize(t_ds *store);
static void	find_soc(t_ds *store, t_node *b, int i);
static void	refresh(t_ds *store, int i, int j);

void	trim(t_ds *store)
{
	while (!is_sorted(store))
	{
		if (back(store->a) != store->arr[store->len_arr - 1]
			&& back(store->a) > front(store->a))
			push_b(store);
		else if (((back(store->a) != store->arr[store->len_arr - 1]
					&& next(store->a) > back(store->a))
				|| back(store->a) == store->arr[store->len_arr - 1])
			&& next(store->a) < front(store->a))
			swap_a(store);
		else
			rotate_a(store);
	}
}

void	organize(t_ds *store)
{
	while (store->len_b)
	{
		find_optimize(store);
		reflect(store);
		push_a(store);
	}
}

static void	find_optimize(t_ds *store)
{
	t_node	*b;
	int		i;

	store->dist_a = -1;
	store->dist_b = -1;
	b = store->b;
	i = -1;
	while (++i < store->len_b)
	{
		find_soc(store, b, i);
		b = b->right;
	}
}

static void	find_soc(t_ds *store, t_node *b, int i)
{
	t_node	*a;
	int		j;

	a = store->a;
	j = -1;
	while (++j < store->len_a)
	{
		if (back(a) > front(a))
		{
			if ((front(b) > back(a)) || (front(b) < front(a)))
				refresh(store, i, j);
		}
		else
			if ((front(b) > back(a)) && (front(b) < front(a)))
				refresh(store, i, j);
		a = a->right;
	}
}

static void	refresh(t_ds *store, int i, int j)
{
	if (store->dist_a == -1)
	{
		store->dist_a = j;
		store->dist_b = i;
	}
	else if (_min(store->dist_a, store->len_a - store->dist_a)
		+ _min(store->dist_b, store->len_b - store->dist_b)
		> _min(i, store->len_b - i)
		+ _min(j, store->len_a - j))
	{
		store->dist_a = j;
		store->dist_b = i;
	}
}
