/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:51:33 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:51:39 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	parse(int argc, char **argv, t_ds *store)
{
	char	**strs;
	int		i;
	int		j;

	i = 0;
	while (++i < argc)
	{
		strs = ft_split(argv[i], ' ');
		if (!(*strs))
		{
			free(strs);
			return (-1);
		}
		j = -1;
		while (strs[++j])
			store->av[store->ac++] = strs[j];
		free(strs);
	}
	return (0);
}

void	input(t_ds *store)
{
	int	i;

	i = -1;
	while (++i < store->ac)
		push_back(&(store->a), ft_atoi(store->av[i]));
	store->len_a = store->ac;
	store->len_arr = store->ac;
}

void	pre_sort(t_ds *store)
{
	t_node	*cur;
	int		i;

	cur = store->a;
	i = -1;
	while (++i < store->len_arr)
	{
		store->arr[i] = cur->data;
		cur = cur->right;
	}
	_sort(store->arr, store->len_arr);
}

void	scan(t_ds *store)
{
	read(0, store->buf + store->len_buf, 1);
	while (store->buf[store->len_buf++])
		read(0, store->buf + store->len_buf, 1);
	store->len_buf--;
}
