/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:04:37 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/09 18:52:18 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static int	init(t_env *e, char *argv)
{
	if (!(e->p.win = mlx_new_window(e->p.mlx, e->width, e->height, argv)))
		return (ft_free_return("Failed to open window", 2, e));
	if (!(e->p.mlx = mlx_init()))
		return (ft_free_return("Failed to init mlx", 2, e));
	e->img.ptr = mlx_new_image(e->p.mlx, e->width, e->height);
	e->img.data = (int*)mlx_get_data_addr(e->img.ptr, &e->img.bpp,
			&e->img.size_l, &e->img.endian);
	e->modify = -1;
	apply_color(19, e);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env *e;

	if ( argc != 2)
		return (ft_print_return("Wrong number of arguments", 2));
	if (!(e = malloc(sizeof(*e))))
		return (ft_print_return("Failed to allocate memory", 2));
	if (ft_strequ(argv[1], "julia"))
		init_julia(e);
	else if (ft_strequ(argv[1], "mandelbrot"))
		init_mandel(e);
	if (!(init(e, argv[1])))
		return (0);
	if (ft_strequ(argv[1], "julia"))
		set_julia_thread(e);
	else if (ft_strequ(argv[1], "mandelbrot"))
		set_mandel_thread(e);
	mlx_hook(e->p.win, 2, 0, key_press, e);
	mlx_hook(e->p.win, 6, 0, mouse_move, e);
	mlx_hook(e->p.win, 4, 0, mouse_press, e);
	mlx_hook(e->p.win, 17, 0, mlx_close, e);
	mlx_loop(e->p.mlx);
}
