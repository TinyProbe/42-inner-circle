/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:46:56 by tkong             #+#    #+#             */
/*   Updated: 2022/12/07 21:47:42 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_pixel_put2(t_dat *data, t_i32 x, t_i32 y, t_i32 color)
{
	*(t_u32 *)(data->addr + (y * data->llen + x * (data->bpp / 8))) = color;
}

t_i32	mlx_get_color(t_i32 color, t_i32 which)
{
	if (which == RED)
		return ((color & (0xff << 16)) >> 16);
	else if (which == GREEN)
		return ((color & (0xff << 8)) >> 8);
	else
		return ((color & (0xff << 0)) >> 0);
}

void	mlx_set_color(t_i32 *color, t_i32 to, t_i32 which)
{
	if (which == RED)
	{
		*color &= ((0xff << 24) | (0xff << 8) | (0xff << 0));
		*color |= (to << 16);
	}
	else if (which == GREEN)
	{
		*color &= ((0xff << 24) | (0xff << 16) | (0xff << 0));
		*color |= (to << 8);
	}
	else
	{
		*color &= ((0xff << 24) | (0xff << 16) | (0xff << 8));
		*color |= (to << 0);
	}
}
