/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:51:50 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:51:51 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	rotate_a(t_ds *store, int *i)
{
	if (store->len_a >= 1)
		store->a = store->a->right;
	*i += 3;
}

void	rotate_b(t_ds *store, int *i)
{
	if (store->len_a >= 1)
		store->b = store->b->right;
	*i += 3;
}

void	rerotate_a(t_ds *store, int *i)
{
	if (store->len_a >= 1)
		store->a = store->a->left;
	*i += 4;
}

void	rerotate_b(t_ds *store, int *i)
{
	if (store->len_a >= 1)
		store->b = store->b->left;
	*i += 4;
}

void	rerotate_r(t_ds *store, int *i)
{
	if (store->len_a >= 1)
	{
		store->a = store->a->left;
		store->b = store->b->left;
	}
	*i += 4;
}
