/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:04:25 by tkong             #+#    #+#             */
/*   Updated: 2022/07/08 20:22:02 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void		ft_bzero(void *s, size_t n);
void		ft_putstr_fd(char *s, int fd);
int			ft_isdigit(int c);
static int	abs(int n);
static void	reverse(char *str, int begin, int end);
static void	swap(char *a, char *b);
static char	*strdigit(const char *s);

void	ft_putnbr_fd(int n, int fd)
{
	char	s[15];
	int		i;

	ft_bzero((void *)s, sizeof(s));
	i = 0;
	if (n < 0)
		s[i++] = '-';
	while (n)
	{
		s[i++] = abs(n % 10) + '0';
		n /= 10;
	}
	reverse(s, strdigit(s) - s, i);
	ft_putstr_fd(s, fd);
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
