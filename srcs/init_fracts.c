/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fracts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:18:53 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/10 13:20:00 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandel(t_env *env)
{
	env->misc.x1 = -2.1;
	env->misc.x2 = 0.6;
	env->misc.y1 = -1.2;
	env->misc.y2 = 1.2;
	env->misc.zoom = 400;
	env->misc.max_iteration = 50;
	env->width = 1080;
	env->height = 960;
	env->thr_data.length = 120;
	env->thr_data.pos = 0;
	env->fractal = MANDELBROT;
}

void	init_mandel2(t_env *env)
{
	env->misc.x1 = -1.37;
	env->misc.x2 = -0.12;
	env->misc.y1 = -1.2;
	env->misc.y2 = 1.2;
	env->misc.zoom = 400;
	env->misc.max_iteration = 50;
	env->width = 1080;
	env->height = 960;
	env->thr_data.length = 120;
	env->thr_data.pos = 0;
	env->fractal = MANDEL_2;
}

void	init_ship(t_env *env)
{
	env->misc.x1 = -1.7;
	env->misc.x2 = 0.21;
	env->misc.y1 = -1.71;
	env->misc.y2 = 1.71;
	env->misc.zoom = 400;
	env->misc.max_iteration = 75;
	env->width = 1080;
	env->height = 960;
	env->thr_data.length = 120;
	env->thr_data.pos = 0;
	env->fractal = BURNING_SHIP;
}

void	init_julia(t_env *env)
{
	env->misc.x1 = -1.5;
	env->misc.x2 = 1.5;
	env->misc.y1 = -1.5;
	env->misc.y2 = 1.5;
	env->c.r = 0.285;
	env->c.i = -0.01;
	env->width = 900;
	env->height = 900;
	env->misc.zoom = 300;
	env->misc.max_iteration = 50;
	env->fractal = JULIA;
	env->thr_data.length = 100;
	env->thr_data.pos = 0;
}

void	init_fracts(char *str, t_env *e)
{
	if (ft_strequ(str, "julia"))
		init_julia(e);
	if (ft_strequ(str, "mandelbrot"))
		init_mandel(e);
	if (ft_strequ(str, "ship"))
		init_ship(e);
	if (ft_strequ(str, "mandel2"))
		init_mandel2(e);
}
