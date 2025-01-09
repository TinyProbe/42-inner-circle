/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:54 by tkong             #+#    #+#             */
/*   Updated: 2022/12/08 17:02:28 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	screen_up(t_db *db)
{
	t_f64	cpxpp;
	t_i32	movedp;

	db->frac.max.im += db->frac.fact.im * MOVE_UNIT;
	db->frac.min.im += db->frac.fact.im * MOVE_UNIT;
	cpxpp = ft_abs(db->frac.max.im - db->frac.min.im) / HEIGHT;
	movedp = db->frac.fact.im * MOVE_UNIT / cpxpp;
	db->pix.x = -1;
	while (++(db->pix.x) < WIDTH)
	{
		db->pix.y = HEIGHT;
		while (db->pix.y-- - movedp)
		{
			db->frac.itpp[db->pix.y * WIDTH + db->pix.x]
				= db->frac.itpp[(db->pix.y - movedp) * WIDTH + db->pix.x];
			if (db->pix.y - movedp < movedp)
				db->frac.itpp[(db->pix.y - movedp) * WIDTH + db->pix.x] = 0;
		}
	}
	render(db);
}

void	screen_down(t_db *db)
{
	t_f64	cpxpp;
	t_i32	movedp;

	db->frac.max.im -= db->frac.fact.im * MOVE_UNIT;
	db->frac.min.im -= db->frac.fact.im * MOVE_UNIT;
	cpxpp = ft_abs(db->frac.max.im - db->frac.min.im) / HEIGHT;
	movedp = db->frac.fact.im * MOVE_UNIT / cpxpp;
	db->pix.x = -1;
	while (++(db->pix.x) < WIDTH)
	{
		db->pix.y = -1;
		while (++(db->pix.y) + movedp < HEIGHT)
		{
			db->frac.itpp[db->pix.y * WIDTH + db->pix.x]
				= db->frac.itpp[(db->pix.y + movedp) * WIDTH + db->pix.x];
			if (db->pix.y + movedp >= HEIGHT - movedp)
				db->frac.itpp[(db->pix.y + movedp) * WIDTH + db->pix.x] = 0;
		}
	}
	render(db);
}

void	screen_left(t_db *db)
{
	t_f64	cpxpp;
	t_i32	movedp;

	db->frac.max.re -= db->frac.fact.re * MOVE_UNIT;
	db->frac.min.re -= db->frac.fact.re * MOVE_UNIT;
	cpxpp = ft_abs(db->frac.max.im - db->frac.min.im) / HEIGHT;
	movedp = db->frac.fact.im * MOVE_UNIT / cpxpp;
	db->pix.y = -1;
	while (++(db->pix.y) < HEIGHT)
	{
		db->pix.x = WIDTH;
		while (db->pix.x-- - movedp)
		{
			db->frac.itpp[db->pix.y * WIDTH + db->pix.x]
				= db->frac.itpp[db->pix.y * WIDTH + (db->pix.x - movedp)];
			if (db->pix.x - movedp < movedp)
				db->frac.itpp[db->pix.y * WIDTH + (db->pix.x - movedp)] = 0;
		}
	}
	render(db);
}

void	screen_right(t_db *db)
{
	t_f64	cpxpp;
	t_i32	movedp;

	db->frac.max.re += db->frac.fact.re * MOVE_UNIT;
	db->frac.min.re += db->frac.fact.re * MOVE_UNIT;
	cpxpp = ft_abs(db->frac.max.im - db->frac.min.im) / HEIGHT;
	movedp = db->frac.fact.im * MOVE_UNIT / cpxpp;
	db->pix.y = -1;
	while (++(db->pix.y) < HEIGHT)
	{
		db->pix.x = -1;
		while (++(db->pix.x) + movedp < WIDTH)
		{
			db->frac.itpp[db->pix.y * WIDTH + db->pix.x]
				= db->frac.itpp[db->pix.y * WIDTH + (db->pix.x + movedp)];
			if (db->pix.x + movedp >= WIDTH - movedp)
				db->frac.itpp[db->pix.y * WIDTH + (db->pix.x + movedp)] = 0;
		}
	}
	render(db);
}
