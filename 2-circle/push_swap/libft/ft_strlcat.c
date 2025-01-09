/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:35:03 by tkong             #+#    #+#             */
/*   Updated: 2022/07/18 17:53:37 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BYTE	unsigned char
#define UNT_T	unsigned long long
#define UNTSIZE	8

static void	cat64(long long *pp1, long long *pp2, size_t *pn);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	long long	p[2];
	size_t		len[2];
	size_t		n;

	len[0] = ft_strlen(dst);
	len[1] = ft_strlen(src);
	p[0] = (long long) dst + len[0];
	p[1] = (long long) src;
	if (len[0] >= size)
		return (len[1] + size);
	n = size - (len[0] + 1);
	if (n > len[1])
		n = len[1];
	if (n >= UNTSIZE)
		cat64(p, p + 1, &n);
	while (n--)
		*(BYTE *) p[0]++ = *(BYTE *) p[1]++;
	*(BYTE *) p[0] = '\0';
	return (len[0] + len[1]);
}

static void	cat64(long long *pp1, long long *pp2, size_t *pn)
{
	while (*pn >= UNTSIZE * 8)
	{
		((UNT_T *) *pp1)[0] = ((UNT_T *) *pp2)[0];
		((UNT_T *) *pp1)[1] = ((UNT_T *) *pp2)[1];
		((UNT_T *) *pp1)[2] = ((UNT_T *) *pp2)[2];
		((UNT_T *) *pp1)[3] = ((UNT_T *) *pp2)[3];
		((UNT_T *) *pp1)[4] = ((UNT_T *) *pp2)[4];
		((UNT_T *) *pp1)[5] = ((UNT_T *) *pp2)[5];
		((UNT_T *) *pp1)[6] = ((UNT_T *) *pp2)[6];
		((UNT_T *) *pp1)[7] = ((UNT_T *) *pp2)[7];
		*pp1 += UNTSIZE * 8;
		*pp2 += UNTSIZE * 8;
		*pn -= UNTSIZE * 8;
	}
	while (*pn >= UNTSIZE)
	{
		*(UNT_T *) *pp1 = *(UNT_T *) *pp2;
		*pp1 += UNTSIZE;
		*pp2 += UNTSIZE;
		*pn -= UNTSIZE;
	}
}
