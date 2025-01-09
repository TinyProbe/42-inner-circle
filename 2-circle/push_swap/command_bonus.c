/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:51:52 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:51:53 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_a(t_ds *store, int *i)
{
	if (store->len_a >= 2)
		_swap(&(store->a->data), &(store->a->right->data));
	*i += 3;
}

void	swap_b(t_ds *store, int *i)
{
	if (store->len_b >= 2)
		_swap(&(store->b->data), &(store->b->right->data));
	*i += 3;
}

void	push_a(t_ds *store, int *i)
{
	if (store->len_b >= 1)
	{
		push_front(&(store->a), pop_front(&(store->b)));
		store->len_a++;
		store->len_b--;
	}
	*i += 3;
}

void	push_b(t_ds *store, int *i)
{
	if (store->len_a >= 1)
	{
		push_front(&(store->b), pop_front(&(store->a)));
		store->len_a--;
		store->len_b++;
	}
	*i += 3;
}

void	rotate_r(t_ds *store, int *i)
{
	if (store->len_a >= 1)
	{
		store->a = store->a->right;
		store->b = store->b->right;
	}
	*i += 3;
}
