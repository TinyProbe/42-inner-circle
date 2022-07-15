/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:43:41 by tkong             #+#    #+#             */
/*   Updated: 2022/07/13 15:48:34 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#define BYTE	unsigned char
#define UNT_T	unsigned long long
#define UNTSIZE	8

static void	set(long long *pp, size_t *pn, int c);
static void	set64(long long *pp, size_t *pn, UNT_T unit);
static void	set8(long long *pp, size_t *pn, UNT_T unit);

void	*ft_memset(void *s, int c, size_t n)
{
	long long	p;

	p = (long long) s;
	if (n >= UNTSIZE)
	{
		while ((size_t) p % UNTSIZE)
		{
			*(BYTE *) p++ = c;
			n -= 1;
		}
		if (n >= UNTSIZE)
			set(&p, &n, c);
	}
	while (n--)
		*(BYTE *) p++ = c;
	return (s);
}

static void	set(long long *pp, size_t *pn, int c)
{
	UNT_T	unit;

	unit = (unsigned char) c;
	unit |= unit << 8;
	unit |= unit << 16;
	unit |= unit << 32;
	if (*pn >= UNTSIZE * 8)
		set64(pp, pn, unit);
	if (*pn >= UNTSIZE)
		set8(pp, pn, unit);
}

static void	set64(long long *pp, size_t *pn, UNT_T unit)
{
	size_t	cycle;

	cycle = *pn / (UNTSIZE * 8);
	*pn -= cycle * (UNTSIZE * 8);
	while (cycle--)
	{
		((UNT_T *) *pp)[0] = unit;
		((UNT_T *) *pp)[1] = unit;
		((UNT_T *) *pp)[2] = unit;
		((UNT_T *) *pp)[3] = unit;
		((UNT_T *) *pp)[4] = unit;
		((UNT_T *) *pp)[5] = unit;
		((UNT_T *) *pp)[6] = unit;
		((UNT_T *) *pp)[7] = unit;
		*pp += UNTSIZE * 8;
	}
}

static void	set8(long long *pp, size_t *pn, UNT_T unit)
{
	size_t	cycle;

	cycle = *pn / UNTSIZE;
	*pn -= cycle * UNTSIZE;
	while (cycle--)
	{
		*(UNT_T *) *pp = unit;
		*pp += UNTSIZE;
	}
}
