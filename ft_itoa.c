/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:39:07 by tkong             #+#    #+#             */
/*   Updated: 2022/07/08 19:23:00 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		*ft_calloc(size_t count, size_t size);
int			ft_isdigit(int c);
static int	abs(int n);
static void	reverse(char *str, int begin, int end);
static void	swap(char *a, char *b);
static char	*strdigit(const char *s);

char	*ft_itoa(int n)
{
	char	*s;
	int		i;

	s = (char *)ft_calloc(15, sizeof(char));
	i = 0;
	if (n < 0)
		s[i++] = '-';
	while (n)
	{
		s[i++] = abs(n % 10) + '0';
		n /= 10;
	}
	reverse(s, strdigit(s) - s, i);
	return (s);
}

static int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static void	reverse(char *str, int begin, int end)
{
	--begin;
	while (++begin < --end)
		swap(str + begin, str + end);
}

static void	swap(char *a, char *b)
{
	if (a == b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

static char	*strdigit(const char *s)
{
	--s;
	while (*(++s))
		if (ft_isdigit(*s))
			break ;
	return ((char *)s);
}
