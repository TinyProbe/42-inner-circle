/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:32:34 by tkong             #+#    #+#             */
/*   Updated: 2022/08/08 16:51:47 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	check_flag(t_elem *info)
{
	if (!(info->flag ^ (FLAG_MINUS | FLAG_ZERO)))
		return (0);
	if (!(info->flag ^ (FLAG_PLUS | FLAG_SPACE)))
		return (0);
	if (info->spec & (SPEC_O | SPEC_X | SPEC_X_UP)
		&& (info->flag & (FLAG_PLUS | FLAG_SPACE)))
		return (0);
	if (info->flag & FLAG_MINUS && !check_combi_minus(info))
		return (0);
	if (info->flag & FLAG_PLUS && !check_combi_plus(info))
		return (0);
	if (info->flag & FLAG_SPACE && !check_combi_space(info))
		return (0);
	if (info->flag & FLAG_SHARP && !check_combi_sharp(info))
		return (0);
	if (info->flag & FLAG_ZERO && !check_combi_zero(info))
		return (0);
	return (1);
}

int	check_wid(t_elem *info)
{
	return (info->wid ^ (WID_NUM | WID_STAR));
}

int	check_prec(t_elem *info)
{
	if (!(info->prec ^ (PREC_NUM | PREC_STAR)))
		return (0);
	if (info->prec & (PREC_NUM | PREC_STAR)
		&& info->spec & (SPEC_C | SPEC_P | SPEC_N))
		return (0);
	return (1);
}

int	check_len(t_elem *info)
{
	return (!info->len);
}

int	check_spec(t_elem *info)
{
	return (info->spec);
}
