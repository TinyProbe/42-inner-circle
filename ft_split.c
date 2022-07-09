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

void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *s);
void			ft_bzero(void *s, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
static size_t	max_split(const char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	char	*p;
	size_t	len;
	int		i[2];

	strs = (char **)ft_calloc(max_split(s, c) + 1, sizeof(char *));
	p = ft_strchr(s, (int)c);
	len = ft_strlen(s);
	ft_bzero((void *)i, sizeof(i));
	while (p)
	{
		if (s + i[0] != p)
			strs[i[1]++] = ft_substr(s, i[0], p - (s + i[0]));
		i[0] = p - s + 1;
		p = ft_strchr(s + i[0], (int)c);
	}
	if (i[0] != (int)len)
		strs[i[1]++] = ft_substr(s, i[0], len - i[0]);
	return (strs);
}

static size_t	max_split(const char *s, char c)
{
	size_t	amt;

	amt = 1;
	--s;
	while (*(++s))
		if (*s == c)
			++amt;
	return (amt);
}
