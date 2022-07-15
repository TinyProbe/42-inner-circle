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

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strdup(const char *s1)
{
	size_t	size;
	void	*res;

	size = ft_strlen(s1) + 1;
	res = malloc(size);
	if (res)
		return ((char *) ft_memcpy(res, s1, size));
	return (res);
}
