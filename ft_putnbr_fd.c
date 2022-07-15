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

void		ft_putstr_fd(char *s, int fd);
static int	abs2(int n);
static void	reverse(char *str, int begin, int end);
static void	swap(char *a, char *b);

void	ft_putnbr_fd(int n, int fd)
{
	char	buf[12];
	int		i;

	i = 0;
	if (n < 0)
		buf[i++] = '-';
	while (n)
	{
		buf[i++] = abs2(n % 10) + '0';
		n /= 10;
	}
	buf[i] = '\0';
	reverse(buf, buf[0] == '-', i);
	if (!i)
		ft_putstr_fd("0", fd);
	else
		ft_putstr_fd(buf, fd);
}

static int	abs2(int n)
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
