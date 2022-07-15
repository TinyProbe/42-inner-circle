/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:34:03 by tkong             #+#    #+#             */
/*   Updated: 2022/07/14 17:33:27 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_calloc(size_t count, size_t size);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return ((char *) ft_calloc(1, 1));
	if (len > len_s - start)
		len = len_s - start;
	dst = (char *) malloc(len + 1);
	if (!dst)
		return (dst);
	ft_memcpy(dst, s + start, len);
	dst[len] = '\0';
	return (dst);
}
