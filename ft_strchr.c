/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 17:59:57 by tkong             #+#    #+#             */
/*   Updated: 2022/07/06 18:16:16 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlen(const char *s);

char	*ft_strchr(const char *s, int c)
{
	return ((char *) ft_memchr(s, c, ft_strlen(s) + 1));
}
