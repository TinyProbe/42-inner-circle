/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:04:29 by tkong             #+#    #+#             */
/*   Updated: 2022/07/18 17:51:40 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BYTE	unsigned char
#define UNT_T	unsigned long long
#define UNTSIZE	8

static void	copy(long long p1, long long p2, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	copy((long long) dst, (long long) src, n);
	return (dst);
}

static void	copy(long long p1, long long p2, size_t n)
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
