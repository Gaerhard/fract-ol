/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fracts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 14:18:53 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/09 15:48:42 by gaerhard         ###   ########.fr       */
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
	env->thr_data.length = 240;
	env->thr_data.pos = 0;
	env->fractal = MANDELBROT;
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
	env->thr_data.length = 300;
	env->thr_data.pos = 0;
}
