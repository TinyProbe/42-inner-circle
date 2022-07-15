/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:32:28 by tkong             #+#    #+#             */
/*   Updated: 2022/07/13 22:22:34 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#define DIGIT 1
#define WSPACE 2

int				ft_isdigit(int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
static size_t	digitlen(const char *s);
static int		iswhat(int c);
static int		stoi(const char *str, size_t n);
static int		get_sign(const char **pstr);

int	ft_atoi(const char *str)
{
	int			sign;
	size_t		dlen;
	const char	*max;

	while (*str && (iswhat(*str) & WSPACE))
		++str;
	sign = get_sign(&str);
	dlen = digitlen(str);
	max = "9223372036854775808";
	if (sign == 1)
		max = "9223372036854775807";
	if (dlen > 19 || (dlen == 19 && ft_strncmp(str, max, dlen) > 0))
		return (~(sign >> 1));
	return (stoi(str, dlen) * sign);
}

static int	iswhat(int c)
{
	unsigned char	ch;

	ch = c;
	c = 0;
	if (ft_isdigit(ch))
		c += DIGIT;
	if ((ch >= 9 && ch <= 13) || ch == 32)
		c += WSPACE;
	return (c);
}

static int	get_sign(const char **pstr)
{
	if (**pstr == '-')
	{
		++(*pstr);
		return (-1);
	}
	else if (**pstr == '+')
		++(*pstr);
	return (1);
}

static size_t	digitlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && (iswhat(s[len]) & DIGIT))
		++len;
	return (len);
}

static int	stoi(const char *str, size_t n)
{
	long long	res;

	res = 0;
	while (n--)
		res = (res * 10) + (*str++ - '0');
	return (res);
}
