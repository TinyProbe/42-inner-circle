/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:44 by tkong             #+#    #+#             */
/*   Updated: 2022/12/08 17:02:28 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	color_shift(t_db *db, t_i32 shift);

void	gen_color(t_db *db)
{
	t_f64	ratio;

	ratio = (t_f64) db->frac.itpp[WIDTH * db->pix.y + db->pix.x]
		/ db->frac.it_max;
	mlx_set_color(&(db->pix.color),
		(t_u8)(9 * (1 - ratio) * pow(ratio, 3) * 255), RED);
	mlx_set_color(&(db->pix.color),
		(t_u8)(15 * pow((1 - ratio), 2) * pow(ratio, 2) * 255), GREEN);
	mlx_set_color(&(db->pix.color),
		(t_u8)(8.5 * pow((1 - ratio), 3) * ratio * 255), BLUE);
	color_shift(db, db->pix.shift);
}

static void	color_shift(t_db *db, t_i32 shift)
{
	t_f64	ratio;
	t_i32	color_slice;

	if (shift < 1)
		return ;
	ratio = (t_f64)(ft_min(shift, (((1 << 6) - 1) / 3))) / (((1 << 6) - 1) / 3);
	color_slice = 0;
	mlx_set_color(&color_slice,
		mlx_get_color(db->pix.color, RED) * ratio, RED);
	mlx_set_color(&color_slice,
		mlx_get_color(db->pix.color, GREEN) * ratio, GREEN);
	mlx_set_color(&color_slice,
		mlx_get_color(db->pix.color, BLUE) * ratio, BLUE);
	mlx_set_color(&(db->pix.color),
		mlx_get_color(db->pix.color, GREEN) - mlx_get_color(color_slice, GREEN)
		+ mlx_get_color(color_slice, RED), GREEN);
	mlx_set_color(&(db->pix.color),
		mlx_get_color(db->pix.color, BLUE) - mlx_get_color(color_slice, BLUE)
		+ mlx_get_color(color_slice, GREEN), BLUE);
	mlx_set_color(&(db->pix.color),
		mlx_get_color(db->pix.color, RED) - mlx_get_color(color_slice, RED)
		+ mlx_get_color(color_slice, BLUE), RED);
	color_shift(db, shift - (((1 << 6) - 1) / 3));
}

void	color_lshift(t_db *db)
{
	if (db->key_state[KEY_SHIFT])
	{
		db->pix.shift = (db->pix.shift - 1) % (1 << 6);
		printf("color shift : %u\n", db->pix.shift);
		render(db);
	}
}

void	color_rshift(t_db *db)
{
	if (db->key_state[KEY_SHIFT])
	{
		db->pix.shift = (db->pix.shift + 1) % (1 << 6);
		printf("color shift : %u\n", db->pix.shift);
		render(db);
	}
}
