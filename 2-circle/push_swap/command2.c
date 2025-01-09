/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:51:46 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:51:47 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwap.h"

void	rotate_a(t_ds *store)
{
	store->a = store->a->right;
	store->cmd[store->len_cmd++] = RA;
}

void	rotate_b(t_ds *store)
{
	store->b = store->b->right;
	store->cmd[store->len_cmd++] = RB;
}

void	rerotate_a(t_ds *store)
{
	store->a = store->a->left;
	store->cmd[store->len_cmd++] = RRA;
}

void	rerotate_b(t_ds *store)
{
	store->b = store->b->left;
	store->cmd[store->len_cmd++] = RRB;
}

void	rerotate_r(t_ds *store)
{
	store->a = store->a->left;
	store->b = store->b->left;
	store->cmd[store->len_cmd++] = RRR;
}
