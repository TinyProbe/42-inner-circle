/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:16:15 by tkong             #+#    #+#             */
/*   Updated: 2022/07/07 21:52:10 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	--((const char *)s1);
	--((const char *)s2);
	while (n--)
		if (*(++((const char *)s1)) != *(++((const char *)s2)))
			break ;
	return ((int)(*((const unsigned char *)s1)) -
			(int)(*((const unsigned char *)s2)));
}
