/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:49:53 by tkong             #+#    #+#             */
/*   Updated: 2022/07/18 17:53:45 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	n;

	len = ft_strlen(src);
	if (!size)
		return (len);
	n = len;
	if (n > size - 1)
		n = size - 1;
	ft_memcpy(dst, src, n);
	dst[n] = '\0';
	return (len);
}
