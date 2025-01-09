/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:52:10 by tkong             #+#    #+#             */
/*   Updated: 2022/09/19 15:52:10 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	_sort(int *arr, int n)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
			if (arr[i] > arr[j])
				_swap(arr + i, arr + j);
	}
}

void	_swap(int *a, int *b)
{
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

long long	_max(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}

long long	_min(long long a, long long b)
{
	if (a < b)
		return (a);
	return (b);
}

long long	_abs(long long a)
{
	if (a < 0)
		return (-a);
	return (a);
}
