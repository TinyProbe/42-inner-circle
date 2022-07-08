/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:32:28 by tkong             #+#    #+#             */
/*   Updated: 2022/07/07 15:43:40 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define IS_DIGIT 1
#define IS_SPACE 2

int			ft_isdigit(int c);
static int	iswhat(int c);
static int	stoi(const char *str);
static int	get_sign(const char **pstr);

int	ft_atoi(const char *str)
{
	while (*str && (iswhat(*str) & IS_SPACE))
		++str;
	return (stoi(str));
}

static int	iswhat(int c)
{
	unsigned char	ch;

	ch = c;
	c = 0;
	if (ft_isdigit(ch))
		c += IS_DIGIT;
	if ((ch >= 9 && ch <= 13) || ch == 32)
		c += IS_SPACE;
	return (c);
}

static int	stoi(const char *str)
{
	long long	res;
	int			sig;
	int			i;

	res = 0ll;
	sig = get_sign(&str);
	i = -1;
	while (str[++i] && (iswhat(str[i]) & IS_DIGIT))
	{
		if (i > 18)
			return (-1);
		res *= 10;
		res += (str[i] - '0');
	}
	return ((int)(res * sig));
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
