/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:51:41 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 18:50:30 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	extract(int argc, char **argv, t_ds *store);
static int	sort(t_ds *store);
static int	sort2(t_ds *store, int *i);
static void	release(t_ds *store);

int	main(int argc, char **argv)
{
	static t_ds	store;

	if (argc <= 1)
		return (0);
	if (extract(argc, argv, &store))
	{
		write(2, "Error\n", 6);
		release(&store);
		return (-1);
	}
	if (is_sorted(&store))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	release(&store);
	return (0);
}

static int	extract(int argc, char **argv, t_ds *store)
{
	if (parse(argc, argv, store))
		return (-1);
	if (valid1(store))
		return (-2);
	input(store);
	pre_sort(store);
	if (valid2(store))
		return (-3);
	scan(store);
	if (sort(store))
		return (-4);
	return (0);
}

static int	sort(t_ds *store)
{
	int	i;

	i = 0;
	while (i < store->len_buf)
	{
		if (ft_strnstr(store->buf + i, "sa\n", 3))
			swap_a(store, &i);
		else if (ft_strnstr(store->buf + i, "sb\n", 3))
			swap_b(store, &i);
		else if (ft_strnstr(store->buf + i, "pa\n", 3))
			push_a(store, &i);
		else if (ft_strnstr(store->buf + i, "pb\n", 3))
			push_b(store, &i);
		else if (sort2(store, &i))
			return (-1);
	}
	return (0);
}

static int	sort2(t_ds *store, int *i)
{
	if (ft_strnstr(store->buf + *i, "ra\n", 3))
		rotate_a(store, i);
	else if (ft_strnstr(store->buf + *i, "rb\n", 3))
		rotate_b(store, i);
	else if (ft_strnstr(store->buf + *i, "rr\n", 3))
		rotate_r(store, i);
	else if (ft_strnstr(store->buf + *i, "rra\n", 4))
		rerotate_a(store, i);
	else if (ft_strnstr(store->buf + *i, "rrb\n", 4))
		rerotate_b(store, i);
	else if (ft_strnstr(store->buf + *i, "rrr\n", 4))
		rerotate_r(store, i);
	else
		return (-1);
	return (0);
}

static void	release(t_ds *store)
{
	while (store->ac--)
		free(store->av[store->ac]);
	while (store->a)
		pop_back(&(store->a));
	while (store->b)
		pop_back(&(store->b));
}
