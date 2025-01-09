/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:46:33 by tkong             #+#    #+#             */
/*   Updated: 2023/03/13 12:50:44 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define HEIGHT			800
# define WIDTH			800
# define TRY_LIMIT		100
# define MAX_ABS		2.0
# define IT_MAX_INIT	50
# define IT_MAX_MAX		1000
# define IT_MAX_MIN		1
# define MOVE_UNIT		20

# include "../ft/ft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>

enum e_color
{
	RED		= 0x00ff0000,
	GREEN	= 0x0000ff00,
	BLUE	= 0x000000ff,
	BLACK	= 0x00000000,
	WHITE	= 0x00ffffff,
};

enum e_keycode
{
	KEY_ESC		= 0x35,
	KEY_SPACE	= 0x31,
	KEY_0		= 0x1D,
	KEY_MINUS	= 0x1B,
	KEY_EQUAL	= 0x18,
	KEY_UP		= 0x7E,
	KEY_DOWN	= 0x7D,
	KEY_LEFT	= 0x7B,
	KEY_RIGHT	= 0x7C,
	KEY_SHIFT	= 0x101,
	KEY_REST	= 0x2B,
	KEY_FSTOP	= 0x2F,
};

enum e_mousecode
{
	LEFT_CLICK	= 0x01,
	RIGHT_CLICK	= 0x02,
	MID_CLICK	= 0x03,
	SCROLL_UP	= 0x04,
	SCROLL_DOWN	= 0x05,
};

enum e_event
{
	KEYDOWN		= 2,
	KEYUP		= 3,
	MOUSEDOWN	= 4,
	MOUSEUP		= 5,
	MOUSEMOVE	= 6,
	EXPOSE		= 12,
	DESTROY		= 17,
};

typedef struct s_cpx
{
	t_f64	re;
	t_f64	im;
}	t_cpx;

typedef struct s_pix
{
	t_i32	x;
	t_i32	y;
	t_i32	color;
	t_u32	shift;
}	t_pix;

typedef struct s_frac
{
	void	(*ftr)();
	t_i32	itpp[WIDTH * HEIGHT];
	t_i32	it_cur;
	t_i32	it_max;
	t_cpx	max;
	t_cpx	min;
	t_cpx	fact;
	t_cpx	z;
	t_cpx	c;
	t_cpx	k;
}	t_frac;

typedef struct s_dat
{
	void	*img;
	t_i8	*addr;
	t_i32	bpp;
	t_i32	llen;
	t_i32	endian;
}	t_dat;

typedef struct s_db
{
	t_i32	init_try;
	void	*mlx;
	void	*win;
	t_dat	dat;
	t_frac	frac;
	t_pix	pix;
	t_bool	key_state[0xffff];
}	t_db;

void	mlx_pixel_put2(t_dat *data, t_i32 x, t_i32 y, t_i32 color);
t_i32	mlx_get_color(t_i32 color, t_i32 which);
void	mlx_set_color(t_i32 *color, t_i32 to, t_i32 which);

t_cpx	make_cpx(t_f64 re, t_f64 im);

t_i32	execute(t_db *db);
void	render(t_db *db);

void	gen_color(t_db *db);

t_i32	key_press(t_i32 code, t_db *db);
t_i32	key_release(t_i32 keycode, t_db *db);
t_i32	quit(void);
t_i32	set_k(t_db *db);
void	it_reset(t_db *db);
void	it_incre(t_db *db);
void	it_decre(t_db *db);
void	screen_up(t_db *db);
void	screen_down(t_db *db);
void	screen_left(t_db *db);
void	screen_right(t_db *db);
void	color_lshift(t_db *db);
void	color_rshift(t_db *db);

t_i32	mouse_down(t_i32 code, t_i32 x, t_i32 y, t_db *db);
void	zoom(t_i32 code, t_i32 x, t_i32 y, t_db *db);

void	mandelbrot(t_db *db);
void	julia(t_db *db);
void	mandelbar(t_db *db);

#endif
