/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:26:47 by tkong             #+#    #+#             */
/*   Updated: 2022/08/12 16:46:00 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	itodec(t_elem *info, int i)
{
	info->neg = ((UINT32) i & (1u << 31) || 0);
	if (!i)
	{
		if (!(info->prec) || info->precis)
			info->res[info->end++] = '0';
		return ;
	}
	while (i)
	{
		info->res[info->end++] = _abs(i % 10) + '0';
		i /= 10;
	}
	_rev(info->res, info->begin, info->end);
}

void	utodec(t_elem *info, UINT32 u)
{
	if (!u)
	{
		if (!(info->prec) || info->precis)
			info->res[info->end++] = '0';
		return ;
	}
	while (u)
	{
		info->res[info->end++] = u % 10 + '0';
		u /= 10;
	}
	_rev(info->res, info->begin, info->end);
}

void	ulltohex(t_elem *info, UINT64 ull, int up)
{
	const char	*hexchr;

	hexchr = "0123456789abcdef";
	if (up)
		hexchr = "0123456789ABCDEF";
	if (!ull)
	{
		info->flag -= (info->flag & FLAG_SHARP);
		if (!(info->prec) || info->precis)
			info->res[info->end++] = '0';
		return ;
	}
	while (ull)
	{
		info->res[info->end++] = hexchr[ull % 16];
		ull /= 16;
	}
	_rev(info->res, info->begin, info->end);
}

void	ptohex(t_elem *info, void *p)
{
	const char *const	hexchr = "0123456789abcdef";
	UINT64				ull;

	ull = (UINT64) p;
	if (!ull)
	{
		info->res[info->end++] = '0';
		return ;
	}
	while (ull)
	{
		info->res[info->end++] = hexchr[ull % 16];
		ull /= 16;
	}
	_rev(info->res, info->begin, info->end);
}
