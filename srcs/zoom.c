/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:48:47 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/10 14:05:02 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(int mouse_x, int mouse_y, t_env *env)
{
	double x;
	double y;

	x = mouse_x;
	y = mouse_y;
	env->misc.x1 = (x / env->misc.zoom + env->misc.x1)
		- (x / (env->misc.zoom * 1.5));
	env->misc.y1 = (y / env->misc.zoom + env->misc.y1)
		- (y / (env->misc.zoom * 1.5));
	env->misc.zoom *= 1.5;
	env->misc.max_iteration += 5;
}

void	zoom_out(int mouse_x, int mouse_y, t_env *env)
{
	double x;
	double y;

	x = mouse_x;
	y = mouse_y;
	if (env->misc.zoom > 25)
	{
		env->misc.x1 = (x / env->misc.zoom + env->misc.x1)
			- (x / (env->misc.zoom / 1.5));
		env->misc.y1 = (y / env->misc.zoom + env->misc.y1)
			- (y / (env->misc.zoom / 1.5));
		env->misc.zoom /= 1.5;
		env->misc.max_iteration -= (env->misc.max_iteration <= 25) ? 0 : 5;
	}
}
