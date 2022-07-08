/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:18:11 by tkong             #+#    #+#             */
/*   Updated: 2022/07/08 10:30:42 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t		ft_strlen(const char *s);
static char	*strncpy(char *dst, const char *src, size_t size);

char	*ft_strdup(const char *s1)
{
	size_t	size;

	size = ft_strlen(s1) + 1;
	return (strncpy((char *)malloc(size), s1, size));
}

static char	*strncpy(char *dst, const char *src, size_t size)
{
	if (dst)
		while (size--)
			dst[size] = src[size];
	return (dst);
}
