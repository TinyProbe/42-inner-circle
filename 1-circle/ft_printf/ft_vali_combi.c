/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vali_combi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 11:01:13 by tkong             #+#    #+#             */
/*   Updated: 2022/08/11 14:04:56 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_combi_minus(t_elem *info)
{
	(void) info;
	return (1);
}

int	check_combi_plus(t_elem *info)
{
	return (!(info->spec & (SPEC_U | SPEC_X | SPEC_X_UP
				| SPEC_C | SPEC_S | SPEC_P)));
}

int	check_combi_space(t_elem *info)
{
	return (!(info->spec & (SPEC_U | SPEC_X | SPEC_X_UP
				| SPEC_C | SPEC_S | SPEC_P)));
}

int	check_combi_sharp(t_elem *info)
{
	return (info->spec & (SPEC_O | SPEC_X | SPEC_X_UP
			| SPEC_PERCENT));
}

int	check_combi_zero(t_elem *info)
{
	return (!(info->spec & (SPEC_C | SPEC_S | SPEC_P | SPEC_N)));
}
