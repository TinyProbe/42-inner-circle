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
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char *)s1 - 1;
	m2 = (unsigned char *)s2 - 1;
	while (n && *(++m1) == *(++m2))
		--n;
	if (n)
		return ((int)*m1 - (int)*m2);
	return (0);
}
