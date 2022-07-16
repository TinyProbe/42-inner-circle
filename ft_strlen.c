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

size_t	ft_strlen(const char *s)
{
	long long	p;

	p = (long long) s;
	while (1)
	{
		if (!((BYTE *) p)[0])
			return (p - (long long) s);
		else if (!((BYTE *) p)[1])
			return (p + 1 - (long long) s);
		else if (!((BYTE *) p)[2])
			return (p + 2 - (long long) s);
		else if (!((BYTE *) p)[3])
			return (p + 3 - (long long) s);
		else if (!((BYTE *) p)[4])
			return (p + 4 - (long long) s);
		else if (!((BYTE *) p)[5])
			return (p + 5 - (long long) s);
		else if (!((BYTE *) p)[6])
			return (p + 6 - (long long) s);
		else if (!((BYTE *) p)[7])
			return (p + 7 - (long long) s);
		p += 8;
	}
}
