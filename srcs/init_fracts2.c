/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fracts2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 15:14:48 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/10 15:32:07 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	init_mandel4(t_env *env)
{
	env->misc.x1 = -1.37;
	env->misc.x2 = -0.12;
	env->misc.y1 = -1.2;
	env->misc.y2 = 1.2;
	env->misc.zoom = 400;
	env->misc.max_iteration = 25;
	env->width = 1080;
	env->height = 960;
	env->thr_data.length = 120;
	env->thr_data.pos = 0;
	env->fractal = MANDEL_4;
}
