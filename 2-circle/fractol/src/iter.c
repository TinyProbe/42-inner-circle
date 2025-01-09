/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:46:39 by tkong             #+#    #+#             */
/*   Updated: 2022/12/07 21:47:42 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_i32	set_k(t_db *db)
{
	t_i32	x;
	t_i32	y;

	if (db->key_state[KEY_SPACE] == FALSE)
		return (0);
	mlx_mouse_get_pos(db->win, &x, &y);
	db->frac.k = make_cpx(
			db->frac.min.re + x * db->frac.fact.re,
			db->frac.max.im - y * db->frac.fact.im);
	ft_bzero(db->frac.itpp, sizeof(t_i32) * WIDTH * HEIGHT);
	render(db);
	return (0);
}

void	it_reset(t_db *db)
{
	if (db->frac.it_max != IT_MAX_INIT)
	{
		db->frac.it_max = IT_MAX_INIT;
		printf("it_max : %d\n", db->frac.it_max);
		db->frac.max = make_cpx(MAX_ABS, MAX_ABS);
		db->frac.min = make_cpx(-MAX_ABS, -MAX_ABS);
		db->frac.k = make_cpx(-0.56, 0.48);
		db->pix.shift = 0;
		ft_bzero(db->frac.itpp, sizeof(t_i32) * WIDTH * HEIGHT);
		render(db);
	}
}

void	it_incre(t_db *db)
{
	if (db->frac.it_max < IT_MAX_MAX)
	{
		printf("it_max : %d\n", ++(db->frac.it_max));
		render(db);
	}
}

void	it_decre(t_db *db)
{
	if (db->frac.it_max > IT_MAX_MIN)
	{
		printf("it_max : %d\n", --(db->frac.it_max));
		render(db);
	}
}
