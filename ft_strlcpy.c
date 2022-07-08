/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:49:53 by tkong             #+#    #+#             */
/*   Updated: 2022/07/08 12:24:54 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	int		i;

	len = ft_strlen(src);
	i = -1;
	while (++i < (int)size - 1)
	{
		if (i < len)
			dst[i] = src[i];
		else
			dst[i] = '\0';
	}
	dst[i] = '\0';
	return (len);
}
