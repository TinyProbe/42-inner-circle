/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:16:47 by tkong             #+#    #+#             */
/*   Updated: 2022/08/12 20:07:23 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void			init_info(t_elem *info);
static const char	*set_arg(const char *format, va_list ap, t_elem *info);
static int			cat_arg(char *buf, int idx, t_elem *info);

int	ft_vfprintf(const char *format, va_list ap)
{
	static t_elem	info;
	static char		buf[MAX_SIZE];
	int				idx;

	idx = 0;
	while (*format)
	{
		if (*format == '%')
		{
			init_info(&info);
			format = set_arg(format + 1, ap, &info);
			if (!format)
				return (-1);
			idx = cat_arg(buf, idx, &info);
		}
		else
			buf[idx++] = *format++;
	}
	if (!~write(1, buf, idx))
		return (-1);
	return (idx);
}

static void	init_info(t_elem *info)
{
	info->flag = 0;
	info->wid = 0;
	info->prec = 0;
	info->len = 0;
	info->spec = 0;
	info->width = 0;
	info->precis = 0;
	info->begin = MAX_SIZE / 2;
	info->end = MAX_SIZE / 2;
	info->neg = 0;
}

static const char	*set_arg(const char *format, va_list ap, t_elem *info)
{
	int	idx;

	idx = 0;
	idx = scan_flag(format, idx, info);
	idx = scan_wid(format, idx, info);
	idx = scan_prec(format, idx, info);
	idx = scan_len(format, idx, info);
	idx = scan_spec(format, idx, info);
	if (info->wid & WID_STAR)
		info->width = va_arg(ap, int);
	if (info->prec & PREC_STAR)
		info->precis = va_arg(ap, int);
	if (!(info->spec & SPEC_PERCENT))
		if (!check_prec(info) || !check_len(info) || !check_spec(info)
			|| !check_flag(info) || !check_wid(info)
			|| info->width < 0 || info->precis < 0)
			return (0);
	if (info->spec & SPEC_P)
		info->flag |= FLAG_SHARP;
	if (info->spec & SPEC_PERCENT)
		info->flag -= (info->flag & FLAG_ZERO);
	set_arg_value(ap, info);
	return (format + idx);
}

static int	cat_arg(char *buf, int idx, t_elem *info)
{
	apply_prec(info);
	if (!(info->flag & FLAG_ZERO))
		apply_base(info);
	if (info->flag & FLAG_ZERO)
	{
		apply_wid(info);
		apply_base(info);
	}
	apply_sign(info);
	if (!(info->flag & FLAG_ZERO))
		apply_wid(info);
	while (info->begin < info->end)
		buf[idx++] = info->res[info->begin++];
	return (idx);
}
