/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:23:35 by tkong             #+#    #+#             */
/*   Updated: 2022/07/18 17:54:04 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BYTE	unsigned char
#define UNT_T	unsigned long long
#define UNTSIZE	8

static void	shakecopy(long long p1, long long p2, size_t n,
				char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*dst;
	size_t		n;

	n = ft_strlen(s);
	dst = (char *) malloc(n + 1);
	if (!dst)
		return (dst);
	shakecopy((long long) dst, (long long) s, n, f);
	return (dst);
}

static void	shakecopy(long long p1, long long p2, size_t n,
		char (*f)(unsigned int, char))
{
	((BYTE *) p1)[n] = '\0';
	while (n >= UNTSIZE)
	{
		n -= UNTSIZE;
		((BYTE *) p1)[n] = f(n, ((BYTE *) p2)[n]);
		((BYTE *) p1)[n + 1] = f(n + 1, ((BYTE *) p2)[n + 1]);
		((BYTE *) p1)[n + 2] = f(n + 2, ((BYTE *) p2)[n + 2]);
		((BYTE *) p1)[n + 3] = f(n + 3, ((BYTE *) p2)[n + 3]);
		((BYTE *) p1)[n + 4] = f(n + 4, ((BYTE *) p2)[n + 4]);
		((BYTE *) p1)[n + 5] = f(n + 5, ((BYTE *) p2)[n + 5]);
		((BYTE *) p1)[n + 6] = f(n + 6, ((BYTE *) p2)[n + 6]);
		((BYTE *) p1)[n + 7] = f(n + 7, ((BYTE *) p2)[n + 7]);
	}
	while (n--)
		((BYTE *) p1)[n] = f(n, ((BYTE *) p2)[n]);
}
