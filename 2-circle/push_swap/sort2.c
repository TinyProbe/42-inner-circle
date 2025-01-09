/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:52:07 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:52:08 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwap.h"

static void	mnmx(t_ds *store, int *mn, int *mx);

int	is_sorted(t_ds *store)
{
	t_node	*cur;
	int		mn;
	int		mx;
	int		i;

	cur = store->a;
	mnmx(store, &mn, &mx);
	i = -1;
	while (++i < store->len_a)
	{
		if (back(cur) > front(cur) && (back(cur) != mx || front(cur) != mn))
			return (0);
		cur = cur->right;
	}
	return (1);
}

static void	mnmx(t_ds *store, int *mn, int *mx)
{
	t_node	*cur;
	int		i;

	*mn = (int) 1e9;
	*mx = (int) -1e9;
	cur = store->a;
	i = -1;
	while (++i < store->len_a)
	{
		if (*mn > front(cur))
			*mn = front(cur);
		if (*mx < front(cur))
			*mx = front(cur);
		cur = cur->right;
	}
}

void	init(t_ds *store)
{
	t_node	*cur;
	int		i;

	cur = store->a;
	i = -1;
	while (++i < store->len_a && front(cur) != store->arr[0])
		cur = cur->right;
	if (i < store->len_a - i)
		while (i--)
			rotate_a(store);
	else
		while (store->len_a - i++)
			rerotate_a(store);
}
