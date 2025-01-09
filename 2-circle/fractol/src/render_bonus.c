/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:51 by tkong             #+#    #+#             */
/*   Updated: 2022/12/08 17:02:28 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	refactor(t_db *db);
static void	iterate(t_db *db);

void	render(t_db *db)
{
	refactor(db);
	db->pix.y = -1;
	while (++(db->pix.y) < HEIGHT)
	{
		db->pix.x = -1;
		while (++(db->pix.x) < WIDTH)
		{
			iterate(db);
			gen_color(db);
			mlx_pixel_put2(&(db->dat), db->pix.x, db->pix.y, db->pix.color);
		}
	}
	mlx_put_image_to_window(db->mlx, db->win, db->dat.img, 0, 0);
}

static void	refactor(t_db *db)
{
	db->frac.fact = make_cpx(
			(db->frac.max.re - db->frac.min.re) / (WIDTH - 1),
			(db->frac.max.im - db->frac.min.im) / (HEIGHT - 1));
}

static void	iterate(t_db *db)
{
	if (db->frac.itpp[WIDTH * db->pix.y + db->pix.x] == 0
		|| db->frac.itpp[WIDTH * db->pix.y + db->pix.x]
		== db->frac.it_max - 1
		|| db->frac.itpp[WIDTH * db->pix.y + db->pix.x]
		== db->frac.it_max + 1)
	{
		db->frac.c = make_cpx(
				db->frac.min.re + db->pix.x * db->frac.fact.re,
				db->frac.max.im - db->pix.y * db->frac.fact.im);
		db->frac.ftr(db);
		db->frac.itpp[WIDTH * db->pix.y + db->pix.x] = db->frac.it_cur;
	}
}
