/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:04:37 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/24 14:51:46 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_env *env;

	if ( argc != 2)
		ft_print_return("Wrong number of arguments", 2);
	if (!(env = malloc(sizeof(*env))))
		ft_print_return("Failed to allocate memory", 2);
	if (!(env->p.mlx = mlx_init()))
		ft_free_return("Failed to init mlx", 2, env);
	if (!(env->p.win = mlx_new_window(env->p.mlx, WIDTH, HEIGHT, argv[1])))
		ft_free_return("Failed to open window", 2, env);
	if (ft_strequ(argv[1], "julia"))
		julia(env);
	else if (ft_strequ(argv[1], "mandelbrot"))
		mandelbrot(env);
	mlx_hook(env->p.win, 2, 0, key_press, env);
	mlx_hook(env->p.win, 17, 0, mlx_close, env);
	mlx_loop(env->p.mlx);
}
