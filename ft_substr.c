/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:34:03 by tkong             #+#    #+#             */
/*   Updated: 2022/07/08 13:06:35 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*strncpy(char *dst, const char *src, size_t size);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	return (strncpy((char *)malloc(len + 1), s + start, len + 1));
}

static char	*strncpy(char *dst, const char *src, size_t size)
{
	if (!dst)
		return (dst);
	dst[--size] = '\0';
	while (size--)
		dst[size] = src[size];
	return (dst);
}
