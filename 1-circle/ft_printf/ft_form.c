/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:27:46 by tkong             #+#    #+#             */
/*   Updated: 2022/08/11 12:39:36 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	scan_flag(const char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = is_flag(form[idx++]);
	while (tmp)
	{
		info->flag |= tmp;
		tmp = is_flag(form[idx++]);
	}
	return (idx - 1);
}

int	scan_wid(const char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = is_wid(form[idx++]);
	while (tmp)
	{
		info->wid |= tmp;
		if (tmp & WID_NUM)
			info->width = info->width * 10 + (form[idx - 1] - '0');
		tmp = is_wid(form[idx++]);
	}
	return (idx - 1);
}

int	scan_prec(const char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = is_prec(form[idx++]);
	if (tmp & PREC_DOT)
	{
		info->prec |= tmp;
		tmp = is_prec(form[idx++]);
		while (tmp)
		{
			info->prec |= tmp;
			if (tmp & PREC_NUM)
				info->precis = info->precis * 10 + (form[idx - 1] - '0');
			tmp = is_prec(form[idx++]);
		}
	}
	return (idx - 1);
}

int	scan_len(const char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = is_len(form[idx++]);
	while (tmp)
	{
		info->len += tmp;
		tmp = is_len(form[idx++]);
	}
	return (idx - 1);
}

int	scan_spec(const char *form, int idx, t_elem *info)
{
	int	tmp;

	tmp = is_spec(form[idx++]);
	if (tmp)
		info->spec |= tmp;
	return (idx);
}
