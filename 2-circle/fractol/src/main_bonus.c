/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:01:30 by tkong             #+#    #+#             */
/*   Updated: 2023/03/13 12:54:41 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void		*which_fractol(t_i8 *av, t_db *db);
static t_i32	error(void);
static void		manual(void);

t_i32	main(t_i32 ac, t_i8 **av)
{
	t_db	db;

	ft_bzero(&db, sizeof(t_db));
	if (ac == 2 && which_fractol(av[1], &db))
		if (execute(&db))
			error();
	manual();
	exit(0);
}

static void	*which_fractol(t_i8 *av, t_db *db)
{
	if (!ft_strcmp(av, "1") || !ft_strcmp(av, "mandelbrot"))
		db->frac.ftr = mandelbrot;
	else if (!ft_strcmp(av, "2") || !ft_strcmp(av, "julia"))
		db->frac.ftr = julia;
	else if (!ft_strcmp(av, "3") || !ft_strcmp(av, "mandelbar"))
		db->frac.ftr = mandelbar;
	return (db->frac.ftr);
}

static t_i32	error(void)
{
	perror("Unknown error occurred.");
	exit(-1);
}

static void	manual(void)
{
	printf("# Usage:                        \n");
	printf("    $ ./fractal [NUM or NAME]   \n");
	printf("                                \n");
	printf("# Available Fractal List:       \n");
	printf("    1. mandelbrot               \n");
	printf("    2. julia                    \n");
	printf("    3. mandelbar                \n");
	printf("                                \n");
}
