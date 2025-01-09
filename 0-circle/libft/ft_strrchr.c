/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:07:29 by tkong             #+#    #+#             */
/*   Updated: 2022/07/18 17:54:33 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BYTE	unsigned char
#define UNT_T	unsigned long long
#define UNTSIZE	8

static void	check8(long long *pp, size_t *pn, int c);

char	*ft_strrchr(const char *s, int c)
{
	long long	p;
	size_t		n;

	n = ft_strlen(s) + 1;
	p = (long long) s + n;
	if (n >= UNTSIZE)
		check8(&p, &n, c);
	while (n--)
		if (*(BYTE *)--p == (BYTE) c)
			return ((void *) p);
	return ((void *) 0);
}

static void	check8(long long *pp, size_t *pn, int c)
{
	UNT_T	rpt_one;
	UNT_T	rpt_c;
	UNT_T	unit;

	rpt_one = 0x0101010101010101;
	rpt_c = c | (c << 8);
	rpt_c |= rpt_c << 16;
	rpt_c |= rpt_c << 32;
	while (*pn >= UNTSIZE)
	{
		*pp -= UNTSIZE;
		*pn -= UNTSIZE;
		unit = *(UNT_T *) *pp ^ rpt_c;
		if (((unit - rpt_one) & ~unit) & (rpt_one << 7))
		{
			*pp += UNTSIZE;
			*pn += UNTSIZE;
			break ;
		}
	}
}
