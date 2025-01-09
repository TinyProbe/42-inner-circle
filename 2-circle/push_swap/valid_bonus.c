/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:52:13 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:52:14 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	valid1_1(char *s);

int	valid1(t_ds *store)
{
	int	i;
	int	j;

	i = -1;
	while (++i < store->ac)
	{
		j = 0;
		if (store->av[i][j] != '-' && store->av[i][j] != '+')
			--j;
		while (store->av[i][++j])
			if (store->av[i][j] < '0' || store->av[i][j] > '9')
				return (-1);
		if (valid1_1(store->av[i]))
			return (-2);
	}
	return (0);
}

static int	valid1_1(char *s)
{
	const char	*rng;
	int			len;

	rng = "2147483647";
	if (*s == '+' || *s == '-')
		if (*s++ == '-')
			rng = "2147483648";
	len = ft_strlen(s);
	if (len > 10 || (len == 10 && ft_memcmp(s, rng, 10) > 0))
		return (-1);
	return (0);
}

int	valid2(t_ds *store)
{
	int	i;

	i = 0;
	while (++i < store->len_arr)
		if (store->arr[i - 1] == store->arr[i])
			return (-1);
	return (0);
}

int	is_sorted(t_ds *store)
{
	t_node	*cur;
	int		i;

	cur = store->a;
	i = -1;
	if (store->len_a != store->len_arr)
		return (0);
	while (++i < store->len_arr)
	{
		if (cur->data != store->arr[i])
			return (0);
		cur = cur->right;
	}
	return (1);
}
