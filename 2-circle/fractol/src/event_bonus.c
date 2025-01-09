/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:01 by tkong             #+#    #+#             */
/*   Updated: 2022/12/08 17:02:28 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

t_i32	key_press(t_i32 keycode, t_db *db)
{
	db->key_state[keycode] = TRUE;
	if (keycode == KEY_ESC)
		quit();
	else if (keycode == KEY_0)
		it_reset(db);
	else if (keycode == KEY_MINUS)
		it_decre(db);
	else if (keycode == KEY_EQUAL)
		it_incre(db);
	else if (keycode == KEY_UP)
		screen_up(db);
	else if (keycode == KEY_DOWN)
		screen_down(db);
	else if (keycode == KEY_LEFT)
		screen_left(db);
	else if (keycode == KEY_RIGHT)
		screen_right(db);
	else if (keycode == KEY_REST)
		color_lshift(db);
	else if (keycode == KEY_FSTOP)
		color_rshift(db);
	return (0);
}

t_i32	key_release(t_i32 keycode, t_db *db)
{
	db->key_state[keycode] = FALSE;
	return (0);
}

t_i32	mouse_down(t_i32 code, t_i32 x, t_i32 y, t_db *db)
{
	if (code == SCROLL_UP || code == SCROLL_DOWN)
		zoom(code, x, y, db);
	return (0);
}
