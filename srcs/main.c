/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:04:37 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/10 15:47:12 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	mlx_red_close(t_env *e)
{
	mlx_close("exiting fract-ol", 2, e);
	return (0);
}

static void	init(t_env *e, char *av)
{
	if (!(e->p.mlx = mlx_init()))
		mlx_close("Failed to init mlx", 2, e);
	if (!(e->p.win = mlx_new_window(e->p.mlx, e->width, e->height, av)))
		mlx_close("Failed to open window", 2, e);
	if (!(e->img.ptr = mlx_new_image(e->p.mlx, e->width, e->height)))
		mlx_close("Failed to create image", 2, e);
	if (!(e->img.data = (int*)mlx_get_data_addr(e->img.ptr, &e->img.bpp,
			&e->img.size_l, &e->img.endian)))
		mlx_close("Failed to obtain image address", 2, e);
	e->modify = -1;
	apply_color(19, e);
}

static void	set_thread(t_env *e)
{
	if (e->fractal == JULIA)
		set_julia_thread(e);
	else if (e->fractal == MANDELBROT)
		set_mandel_thread(e);
	else if (e->fractal == BURNING_SHIP)
		set_ship_thread(e);
	else if (e->fractal == MANDEL_2)
		set_mandel2_thread(e);
	else if (e->fractal == MANDEL_4)
		set_mandel4_thread(e);
}

static char	*usage(void)
{
	char *str;

	str = "usage: ./fractol param\nmandelbrot\njulia\nmandel2\nship\nmandel4";
	return (str);
}

int			main(int argc, char **av)
{
	t_env *e;

	if (argc != 2)
		return (ft_print_return(usage(), 2));
	if (!(e = malloc(sizeof(*e))))
		return (ft_print_return("Failed to allocate memory", 2));
	if (!ft_strequ(av[1], "julia") && !ft_strequ(av[1], "mandelbrot")
		&& !ft_strequ(av[1], "ship") && !ft_strequ(av[1], "mandel2")
		&& !ft_strequ(av[1], "mandel4"))
		return (ft_free_return(usage(), 2, e));
	init_fracts(av[1], e);
	init(e, av[1]);
	set_thread(e);
	mlx_hook(e->p.win, 2, 0, key_press, e);
	mlx_hook(e->p.win, 6, 0, mouse_move, e);
	mlx_hook(e->p.win, 4, 0, mouse_press, e);
	mlx_hook(e->p.win, 17, 0, mlx_red_close, e);
	mlx_loop(e->p.mlx);
}
