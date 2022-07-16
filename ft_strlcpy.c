/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:49:53 by tkong             #+#    #+#             */
/*   Updated: 2022/07/13 19:31:51 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

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
