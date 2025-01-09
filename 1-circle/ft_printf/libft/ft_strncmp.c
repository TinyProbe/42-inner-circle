/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:25:11 by tkong             #+#    #+#             */
/*   Updated: 2022/07/18 17:54:13 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	tmp;

	tmp = ft_strlen(s1) + 1;
	if (n > tmp)
		n = tmp;
	tmp = ft_strlen(s2) + 1;
	if (n > tmp)
		n = tmp;
	return (ft_memcmp(s1, s2, n));
}
