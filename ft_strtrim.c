/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:48:58 by tkong             #+#    #+#             */
/*   Updated: 2022/07/08 15:45:36 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#define CODE_SIZE 256

void			ft_bzero(void *s, size_t n);
static void		make_code(unsigned char *code, const char *set);
static char		*trimmed_str(const char *s, const unsigned char *code);
static size_t	trimmed_size(const char **s, const unsigned char *code);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	code[CODE_SIZE];

	make_code(code, set);
	return (trimmed_str(s1, code));
}

static void	make_code(unsigned char *code, const char *set)
{
	ft_bzero((void *)code, CODE_SIZE);
	--set;
	while (*(++set))
		code[(int)(*set)] = 1;
}

static char	*trimmed_str(const char *s, const unsigned char *code)
{
	size_t	size;
	char	*dst;

	size = trimmed_size(&s, code);
	dst = (char *)malloc(size);
	if (dst)
		while (size--)
			if (!code[(int)(*(--s))])
				dst[size] = *s;
	return (dst);
}

static size_t	trimmed_size(const char **s, const unsigned char *code)
{
	size_t	size;

	size = 1;
	--(*s);
	while (*(++(*s)))
		if (!code[(int)(**s)])
			++size;
	++(*s);
	return (size);
}
