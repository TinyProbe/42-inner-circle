/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:28:21 by tkong             #+#    #+#             */
/*   Updated: 2022/07/13 15:42:10 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#define BYTE	unsigned char

static size_t	find_null(long long p);

size_t	ft_strlen(const char *s)
{
	long long	p;

	p = (long long) s;
	return (find_null(p) - (size_t) s);
}

static size_t	find_null(long long p)
{
	while (1)
	{
		if (!((BYTE *) p)[0])
			return (p);
		else if (!((BYTE *) p)[1])
			return (p + 1);
		else if (!((BYTE *) p)[2])
			return (p + 2);
		else if (!((BYTE *) p)[3])
			return (p + 3);
		else if (!((BYTE *) p)[4])
			return (p + 4);
		else if (!((BYTE *) p)[5])
			return (p + 5);
		else if (!((BYTE *) p)[6])
			return (p + 6);
		else if (!((BYTE *) p)[7])
			return (p + 7);
		p += 8;
	}
}
