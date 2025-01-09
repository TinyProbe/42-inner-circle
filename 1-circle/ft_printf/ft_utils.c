/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 18:28:17 by tkong             #+#    #+#             */
/*   Updated: 2022/08/11 18:51:03 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	_abs(long long ll)
{
	if (ll < 0)
		return (-ll);
	return (ll);
}

void	_rev(char *str, int begin, int end)
{
	--begin;
	while (++begin < --end)
		_swap(str + begin, str + end);
}

void	_swap(char *a, char *b)
{
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}
