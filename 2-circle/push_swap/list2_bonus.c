/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:51:58 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:51:59 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	front(t_node *head)
{
	return (head->data);
}

int	back(t_node *head)
{
	return (head->left->data);
}

int	next(t_node *head)
{
	return (head->right->data);
}
