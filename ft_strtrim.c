/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:48:58 by tkong             #+#    #+#             */
/*   Updated: 2022/07/18 17:54:43 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define BYTE		unsigned char
#define CODE_SIZE	256

static void		make_code(BYTE *code, const char *set);
static char		*trimmed_str(const char *s, BYTE *code);

char	*ft_strtrim(char const *s1, char const *set)
{
	BYTE	code[CODE_SIZE];

	make_code(code, set - 1);
	return (trimmed_str(s1, code));
}

static void	make_code(BYTE *code, const char *set)
{
	ft_bzero((void *) code, CODE_SIZE);
	while (*++set)
		code[(int) *set] = 1;
}

static char	*trimmed_str(const char *s, BYTE *code)
{
	int	beg;
	int	end;

	beg = -1;
	while (s[++beg])
		if (!code[(int) s[beg]])
			break ;
	end = ft_strlen(s);
	while (end--)
		if (!code[(int) s[end]])
			break ;
	return (ft_substr(s, beg, (end + 1) - beg));
}
