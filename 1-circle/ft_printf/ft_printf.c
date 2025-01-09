/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:53:57 by tkong             #+#    #+#             */
/*   Updated: 2022/08/05 08:30:03 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		rtn;

	va_start(ap, format);
	rtn = ft_vfprintf(format, ap);
	va_end(ap);
	return (rtn);
}
