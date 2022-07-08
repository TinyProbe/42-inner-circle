/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:27:18 by tkong             #+#    #+#             */
/*   Updated: 2022/07/07 21:19:00 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int	i;
	int	increase;

	i = 0;
	increase = 1;
	if (dst > src)
	{
		i = n - 1;
		increase = -increase;
	}
	while (n--)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i += increase;
	}
	return (dst);
}
