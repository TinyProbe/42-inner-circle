/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:51:56 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:51:57 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwap.h"

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
