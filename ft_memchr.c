/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:32:41 by tkong             #+#    #+#             */
/*   Updated: 2022/07/17 17:02:08 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#define BYTE	unsigned char
#define UNT_T	unsigned long long
#define UNTSIZE	8

static void	check(long long *pp, size_t *pn, int c);
static void	check64(long long *pp, size_t *pn, UNT_T rpt_one, UNT_T rpt_c);
static int	check64_(UNT_T rpt_one, UNT_T *unit);
static void	check8(long long *pp, size_t *pn, UNT_T rpt_one, UNT_T rpt_c);

void	*ft_memchr(const void *s, int c, size_t n)
{
	long long	p;

	p = (long long) s;
	if (n >= UNTSIZE)
		check(&p, &n, c);
	while (n--)
		if (*(BYTE *) p++ == (BYTE) c)
			return ((void *)(p - 1));
	return ((void *) 0);
}

static void	check(long long *pp, size_t *pn, int c)
{
	UNT_T	rpt_one;
	UNT_T	rpt_c;

	rpt_one = 0x0101010101010101;
	rpt_c = c | (c << 8);
	rpt_c |= rpt_c << 16;
	rpt_c |= rpt_c << 32;
	if (*pn >= UNTSIZE * 8)
		check64(pp, pn, rpt_one, rpt_c);
	if (*pn >= UNTSIZE)
		check8(pp, pn, rpt_one, rpt_c);
}

static void	check64(long long *pp, size_t *pn, UNT_T rpt_one, UNT_T rpt_c)
{
	UNT_T	unit[8];
	int		i;

	while (*pn >= UNTSIZE * 8)
	{
		unit[0] = ((UNT_T *) *pp)[0] ^ rpt_c;
		unit[1] = ((UNT_T *) *pp)[1] ^ rpt_c;
		unit[2] = ((UNT_T *) *pp)[2] ^ rpt_c;
		unit[3] = ((UNT_T *) *pp)[3] ^ rpt_c;
		unit[4] = ((UNT_T *) *pp)[4] ^ rpt_c;
		unit[5] = ((UNT_T *) *pp)[5] ^ rpt_c;
		unit[6] = ((UNT_T *) *pp)[6] ^ rpt_c;
		unit[7] = ((UNT_T *) *pp)[7] ^ rpt_c;
		i = check64_(rpt_one, unit);
		*pp += UNTSIZE * i;
		*pn -= UNTSIZE * i;
		if (i != 8)
			break ;
	}
}

static int	check64_(UNT_T rpt_one, UNT_T *unit)
{
	int	i;

	i = 8;
	if (((unit[0] - rpt_one) & ~unit[0]) & (rpt_one << 7))
		i = 0;
	else if (((unit[1] - rpt_one) & ~unit[1]) & (rpt_one << 7))
		i = 1;
	else if (((unit[2] - rpt_one) & ~unit[2]) & (rpt_one << 7))
		i = 2;
	else if (((unit[3] - rpt_one) & ~unit[3]) & (rpt_one << 7))
		i = 3;
	else if (((unit[4] - rpt_one) & ~unit[4]) & (rpt_one << 7))
		i = 4;
	else if (((unit[5] - rpt_one) & ~unit[5]) & (rpt_one << 7))
		i = 5;
	else if (((unit[6] - rpt_one) & ~unit[6]) & (rpt_one << 7))
		i = 6;
	else if (((unit[7] - rpt_one) & ~unit[7]) & (rpt_one << 7))
		i = 7;
	return (i);
}

static void	check8(long long *pp, size_t *pn, UNT_T rpt_one, UNT_T rpt_c)
{
	UNT_T	unit;

	while (*pn >= UNTSIZE)
	{
		unit = *(UNT_T *) *pp ^ rpt_c;
		if (((unit - rpt_one) & ~unit) & (rpt_one << 7))
			break ;
		*pp += UNTSIZE;
		*pn -= UNTSIZE;
	}
}
