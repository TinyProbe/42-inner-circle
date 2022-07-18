/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:49:32 by tkong             #+#    #+#             */
/*   Updated: 2022/07/18 14:10:11 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t			ft_strlen(const char *s);
char			*ft_strtrim(char const *s1, char const *set);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
void			*ft_memcpy(void *dst, const void *src, size_t n);
static char		*trim(const char *s, char c);
static size_t	split(const char *trimmed, char **buf, char c);

char	**ft_split(char const *s, char c)
{
	char	*trimmed;
	char	*buf[100000];
	char	**strs;
	size_t	num;

	trimmed = trim(s, c);
	if (!trimmed)
		return ((char **) 0);
	num = split(trimmed, buf, c);
	strs = (char **) malloc(sizeof(char *) * (num + 1));
	ft_memcpy(strs, buf, sizeof(char *) * (num + 1));
	free(trimmed);
	return (strs);
}

static char	*trim(const char *s, char c)
{
	char	*dst;
	char	set[2];
	int		i[2];

	*(unsigned short *) set = (unsigned short) c;
	dst = ft_strtrim(s, set);
	if (!dst)
		return (dst);
	*(long long *) i = (long long) 0;
	while (dst[i[0]])
	{
		if (dst[i[0]] == c && dst[i[0] - 1] == c)
			while (dst[i[0]] == c)
				i[0] += 1;
		if (i[0] ^ i[1])
			dst[i[1]] = dst[i[0]];
		i[0] += 1;
		i[1] += 1;
	}
	dst[i[1]] = '\0';
	return (dst);
}

static size_t	split(const char *trimmed, char **buf, char c)
{
	long long	p1;
	long long	p2;
	size_t		num;

	p1 = (long long) trimmed;
	p2 = (long long) ft_memchr((char *) p1, c, ft_strlen((char *) p1));
	num = 0;
	while (p2)
	{
		buf[num++] = ft_substr((char *) p1, 0, p2 - p1);
		p1 = p2 + 1;
		p2 = (long long) ft_memchr((char *) p1, c, ft_strlen((char *) p1));
	}
	if (*(char *) p1)
		buf[num++] = ft_strdup((char *) p1);
	buf[num] = (char *) 0;
	return (num);
}
