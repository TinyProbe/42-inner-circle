/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:32:41 by tkong             #+#    #+#             */
/*   Updated: 2022/07/07 21:55:09 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n-- && *((const unsigned char *)s) != (unsigned char)c)
		++((const unsigned char *)s);
	if (n < 0)
		return ((void *)0);
	return (s);
}
