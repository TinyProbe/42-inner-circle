/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:51:55 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:51:55 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pwap.h"

void	push_front(t_node **head, int data)
{
	push_back(head, data);
	*head = (*head)->left;
}

void	push_back(t_node **head, int data)
{
	t_node	*tmp;

	if (*head)
	{
		tmp = (*head)->left;
		(*head)->left = (t_node *) malloc(sizeof(t_node));
		(*head)->left->data = data;
		(*head)->left->left = tmp;
		(*head)->left->right = *head;
		tmp->right = (*head)->left;
	}
	else
	{
		*head = (t_node *) malloc(sizeof(t_node));
		(*head)->data = data;
		(*head)->left = *head;
		(*head)->right = *head;
	}
}

int	pop_front(t_node **head)
{
	int		rtn;
	t_node	*tmp;

	rtn = (*head)->data;
	if (*head == (*head)->right)
	{
		free(*head);
		*head = (t_node *) 0;
	}
	else
	{
		(*head)->left->right = (*head)->right;
		(*head)->right->left = (*head)->left;
		tmp = (*head)->right;
		free(*head);
		*head = tmp;
	}
	return (rtn);
}

int	pop_back(t_node **head)
{
	*head = (*head)->left;
	return (pop_front(head));
}
