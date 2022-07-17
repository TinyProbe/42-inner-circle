/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:38:34 by tkong             #+#    #+#             */
/*   Updated: 2022/07/17 17:05:25 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	length[2];
	int		i[2];

	length[0] = ft_strlen(big);
	length[1] = ft_strlen(little);
	if (length[0] > len)
		length[0] = len;
	i[0] = -1;
	while ((size_t)++i[0] + length[1] <= length[0])
	{
		i[1] = -1;
		while ((size_t)++i[1] < length[1])
			if (big[i[0] + i[1]] != little[i[1]])
				break ;
		if ((size_t) i[1] == length[1])
			return ((char *) big + i[0]);
	}
	return ((char *) 0);
}
