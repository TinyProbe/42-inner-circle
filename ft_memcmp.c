/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:16:15 by tkong             #+#    #+#             */
/*   Updated: 2022/07/13 15:01:22 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#define BYTE	unsigned char
#define UNT_T	unsigned long long
#define UNTSIZE	8

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	long long	p1;
	long long	p2;

	p1 = (long long) s1;
	p2 = (long long) s2;
	while (n >= UNTSIZE)
	{
		if (*(UNT_T *) p1 ^ *(UNT_T *) p2)
			break ;
		p1 += UNTSIZE;
		p2 += UNTSIZE;
		n -= UNTSIZE;
	}
	while (n--)
		if (*(BYTE *) p1++ ^ *(BYTE *) p2++)
			break ;
	if (~n)
		return ((int)(*(BYTE *)--p1) - (int)(*(BYTE *)--p2));
	return (0);
}
