/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:10:41 by tkong             #+#    #+#             */
/*   Updated: 2022/07/18 17:53:24 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*dst;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dst = (char *) malloc(len_s1 + len_s2 + 1);
	if (!dst)
		return (dst);
	ft_memcpy(dst, s1, len_s1 + 1);
	ft_memcpy(dst + len_s1, s2, len_s2 + 1);
	return (dst);
}
