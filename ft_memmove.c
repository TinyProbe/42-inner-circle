/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:27:18 by tkong             #+#    #+#             */
/*   Updated: 2022/07/13 15:12:08 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#define BYTE		unsigned char
#define UNT_T		unsigned long long
#define UNTSIZE		8
#define UNT2_T		unsigned int
#define UNT2SIZE	4
#define UNT3_T		unsigned short
#define UNT3SIZE	2

static void	rightshift8(long long p1, long long p2, size_t n);
static void	rightshift4(long long p1, long long p2, size_t n);
static void	rightshiftn(long long p1, long long p2, size_t n, size_t dif);
static void	leftshift8(long long p1, long long p2, size_t n);

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	long long	dif;

	dif = (long long) dst - (long long) src;
	if ((size_t) dif < n)
	{
		if ((size_t) dif >= UNTSIZE)
			rightshift8((long long) dst + n, (long long) src + n, n);
		else if ((size_t) dif >= UNT2SIZE)
			rightshift4((long long) dst + n, (long long) src + n, n);
		else
			rightshiftn((long long) dst + n, (long long) src + n, n, dif);
	}
	else
		leftshift8((long long) dst, (long long) src, n);
	return (dst);
}

void	rightshift8(long long p1, long long p2, size_t n)
{
	while (n >= UNTSIZE * 8)
	{
		p1 -= UNTSIZE * 8;
		p2 -= UNTSIZE * 8;
		n -= UNTSIZE * 8;
		((UNT_T *) p1)[0] = ((UNT_T *) p2)[0];
		((UNT_T *) p1)[1] = ((UNT_T *) p2)[1];
		((UNT_T *) p1)[2] = ((UNT_T *) p2)[2];
		((UNT_T *) p1)[3] = ((UNT_T *) p2)[3];
		((UNT_T *) p1)[4] = ((UNT_T *) p2)[4];
		((UNT_T *) p1)[5] = ((UNT_T *) p2)[5];
		((UNT_T *) p1)[6] = ((UNT_T *) p2)[6];
		((UNT_T *) p1)[7] = ((UNT_T *) p2)[7];
	}
	while (n >= UNTSIZE)
	{
		p1 -= UNTSIZE;
		p2 -= UNTSIZE;
		n -= UNTSIZE;
		*(UNT_T *) p1 = *(UNT_T *) p2;
	}
	while (n--)
		*(BYTE *)--p1 = *(BYTE *)--p2;
}

void	rightshift4(long long p1, long long p2, size_t n)
{
	while (n >= UNTSIZE * 8)
	{
		p1 -= UNT2SIZE * 8;
		p2 -= UNT2SIZE * 8;
		n -= UNT2SIZE * 8;
		((UNT2_T *) p1)[0] = ((UNT2_T *) p2)[0];
		((UNT2_T *) p1)[1] = ((UNT2_T *) p2)[1];
		((UNT2_T *) p1)[2] = ((UNT2_T *) p2)[2];
		((UNT2_T *) p1)[3] = ((UNT2_T *) p2)[3];
		((UNT2_T *) p1)[4] = ((UNT2_T *) p2)[4];
		((UNT2_T *) p1)[5] = ((UNT2_T *) p2)[5];
		((UNT2_T *) p1)[6] = ((UNT2_T *) p2)[6];
		((UNT2_T *) p1)[7] = ((UNT2_T *) p2)[7];
	}
	while (n >= UNTSIZE)
	{
		p1 -= UNT2SIZE;
		p2 -= UNT2SIZE;
		n -= UNT2SIZE;
		*(UNT2_T *) p1 = *(UNT2_T *) p2;
	}
	while (n--)
		*(BYTE *)--p1 = *(BYTE *)--p2;
}

void	rightshiftn(long long p1, long long p2, size_t n, size_t dif)
{
	if (!dif)
		return ;
	while (n)
	{
		if (n >= 1 && dif & 1)
		{
			n -= 1;
			*(BYTE *)--p1 = *(BYTE *)--p2;
		}
		if (n >= 2 && dif & 2)
		{
			n -= 2;
			p1 -= 2;
			p2 -= 2;
			*(UNT3_T *) p1 = *(UNT3_T *) p2;
		}
	}
}

void	leftshift8(long long p1, long long p2, size_t n)
{
	while (n >= UNTSIZE * 8)
	{
		((UNT_T *) p1)[0] = ((UNT_T *) p2)[0];
		((UNT_T *) p1)[1] = ((UNT_T *) p2)[1];
		((UNT_T *) p1)[2] = ((UNT_T *) p2)[2];
		((UNT_T *) p1)[3] = ((UNT_T *) p2)[3];
		((UNT_T *) p1)[4] = ((UNT_T *) p2)[4];
		((UNT_T *) p1)[5] = ((UNT_T *) p2)[5];
		((UNT_T *) p1)[6] = ((UNT_T *) p2)[6];
		((UNT_T *) p1)[7] = ((UNT_T *) p2)[7];
		p1 += UNTSIZE * 8;
		p2 += UNTSIZE * 8;
		n -= UNTSIZE * 8;
	}
	while (n >= UNTSIZE)
	{
		*(UNT_T *) p1 = *(UNT_T *) p2;
		p1 += UNTSIZE;
		p2 += UNTSIZE;
		n -= UNTSIZE;
	}
	while (n--)
		*(BYTE *) p1++ = *(BYTE *) p2++;
}
