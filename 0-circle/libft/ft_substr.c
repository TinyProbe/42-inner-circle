/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:34:03 by tkong             #+#    #+#             */
/*   Updated: 2022/07/18 17:54:52 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
