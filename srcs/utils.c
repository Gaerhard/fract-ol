/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:19:05 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/09 18:58:06 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		color(double iter, t_env *e)
{
	char red;
	char green;
	char blue;
	int color;

	red = 255 * cos(iter * e->col.red);
	green = 255 * cos(iter * e->col.green);
	blue = 255 * cos(iter * e->col.blue);
	*((char*)&color + 0) = red;
	*((char*)&color + 1) = green;
	*((char*)&color + 2) = blue;
	return (color);
}

void	apply_color(int key, t_env *e)
{
	if (key == 18)
	{
		e->col.red = 0.02;
		e->col.green = 0.02;
		e->col.blue = 0.02;
	}
	if (key == 19)
	{
		e->col.red = 0.01;
		e->col.green = 0.02;
		e->col.blue = 0.03;
	}
	if (key == 20)
	{
		e->col.red = 0.01;
		e->col.green = 0.02;
		e->col.blue = 0.03;
	}
	if (key == 21)
	{
		e->col.red = 0.01;
		e->col.green = 0.02;
		e->col.blue = 0.03;
	}
}

int		free_all(t_env *e)
{
	if (e->img.ptr)
		mlx_destroy_image(e->p.mlx, e->img.ptr);
	if (e->p.win)
		mlx_destroy_window(e->p.mlx, e->p.win);
	if (e)
		free(e);
	return (0);
}
