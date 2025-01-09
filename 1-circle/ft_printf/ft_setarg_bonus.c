/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setarg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 12:28:31 by tkong             #+#    #+#             */
/*   Updated: 2022/08/11 19:28:02 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	stores(t_elem *info, const char *s);

void	set_arg_value(va_list ap, t_elem *info)
{
	if (info->spec & SPEC_D_OR_I)
		itodec(info, va_arg(ap, int));
	else if (info->spec & SPEC_U)
		utodec(info, va_arg(ap, UINT32));
	else if (info->spec & SPEC_X)
		ulltohex(info, va_arg(ap, UINT32), 0);
	else if (info->spec & SPEC_X_UP)
		ulltohex(info, va_arg(ap, UINT32), 1);
	else if (info->spec & SPEC_C)
		info->res[info->end++] = va_arg(ap, int);
	else if (info->spec & SPEC_S)
		stores(info, va_arg(ap, const char *));
	else if (info->spec & SPEC_P)
		ptohex(info, va_arg(ap, void *));
	else if (info->spec & SPEC_PERCENT)
		info->res[info->end++] = '%';
}

static void	stores(t_elem *info, const char *s)
{
	const char *const	null = "(null)";
	int					idx;
	int					precis;

	idx = 0;
	precis = 0;
	if (s)
		while (s[idx] && (!info->prec || precis++ < info->precis))
			info->res[info->end++] = s[idx++];
	else
		while (null[idx] && (!info->prec || precis++ < info->precis))
			info->res[info->end++] = null[idx++];
}
