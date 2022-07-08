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

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	dst = (char *)malloc(len + 1);
	if (dst)
		ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
