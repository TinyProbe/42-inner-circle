/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:49:32 by tkong             #+#    #+#             */
/*   Updated: 2022/07/08 18:36:55 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
void			*ft_calloc(size_t count, size_t size);
static size_t	max_split(const char *s, char c);
static char		*strncpy(char *dst, const char *src, size_t size);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*p;
	size_t	len;
	int		i[2];

	strs = (char **)ft_calloc(max_split(s, c) + 1, sizeof(char *));
	p = ft_strchr(s, (int)c);
	len = ft_strlen(s);
	i[0] = 0;
	i[1] = 0;
	while (p)
	{
		if (s + i[0] != p)
			strs[i[1]++] = strncpy((char *)malloc(p - (s + i[0]) + 1),
					s + i[0], p - (s + i[0]) + 1);
		i[0] = p - s + 1;
		p = ft_strchr(s + i[0], (int)c);
	}
	if (i[0] != (int)len)
		strs[i[1]++] = strncpy((char *)malloc(len - i[0] + 1),
				s + i[0], len - i[0] + 1);
	return (strs);
}

static size_t	max_split(const char *s, char c)
{
	size_t	amt;

	amt = 1;
	while (*s)
		if (*(s++) == c)
			++amt;
	return (amt);
}

static char	*strncpy(char *dst, const char *src, size_t size)
{
	if (dst)
	{
		dst[--size] = '\0';
		while (size--)
			dst[size] = src[size];
	}
	return (dst);
}
