/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:16 by tkong             #+#    #+#             */
/*   Updated: 2022/12/08 17:02:28 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static t_i32	initialize(t_db *db);
static void		regist_hook(t_db *db);
static void		init_fractol(t_db *db);

t_i32	execute(t_db *db)
{
	if (initialize(db))
		return (-1);
	regist_hook(db);
	init_fractol(db);
	render(db);
	mlx_loop(db->mlx);
	return (0);
}

static t_i32	initialize(t_db *db)
{
	db->init_try = 0;
	while (db->mlx == NULL && db->init_try++ < TRY_LIMIT)
		db->mlx = mlx_init();
	while (db->win == NULL && db->init_try++ < TRY_LIMIT)
		db->win = mlx_new_window(db->mlx, WIDTH, HEIGHT, "Fractal");
	while (db->dat.img == NULL && db->init_try++ < TRY_LIMIT)
		db->dat.img = mlx_new_image(db->mlx, WIDTH, HEIGHT);
	while (db->dat.addr == NULL && db->init_try++ < TRY_LIMIT)
		db->dat.addr = mlx_get_data_addr(db->dat.img, &(db->dat.bpp),
				&(db->dat.llen), &(db->dat.endian));
	if (db->init_try > TRY_LIMIT)
		return (-1);
	return (0);
}

static void	regist_hook(t_db *db)
{
	mlx_hook(db->win, DESTROY, 0, quit, db);
	mlx_hook(db->win, KEYDOWN, 0, key_press, db);
	mlx_hook(db->win, KEYUP, 0, key_release, db);
	mlx_hook(db->win, MOUSEDOWN, 0, mouse_down, db);
	if (db->frac.ftr == julia)
		mlx_loop_hook(db->mlx, set_k, db);
}

static void	init_fractol(t_db *db)
{
	db->frac.max = make_cpx(MAX_ABS, MAX_ABS);
	db->frac.min = make_cpx(-MAX_ABS, -MAX_ABS);
	db->frac.k = make_cpx(-0.56, 0.48);
	db->frac.it_max = IT_MAX_INIT;
}
