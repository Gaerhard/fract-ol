/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:13:31 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/24 14:22:11 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fractol.h"

int		mandelbrot(t_env *env)
{
	float x;
	float y;
	float i;
	float c_r;
	float c_i;
	float z_r;
	float z_i;
	float tmp;


	i = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			i = 0;
			c_r = x / 400 - 2.1;
			c_i = y / 400 - 1.2;
			z_r = 0.1;
			z_i = 0;
			while (i < MAX_ITERATION && z_r * z_r + z_i * z_i < 4)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i <= 49)
				mlx_pixel_put(env->p.mlx, env->p.win, x, y, 0x00000000 + i * 16777215 / 50);
			if (i == MAX_ITERATION)
				mlx_pixel_put(env->p.mlx, env->p.win, x, y, 0x00FFFFFF);
		}
	}
	return (0);
}

int		julia(t_env *env)
{
	float x;
	float y;
	float i;
	float c_r;
	float c_i;
	float z_r;
	float z_i;
	float tmp;


	i = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			i = 0;
			c_r = 0.285;
			c_i = 0.02;
			z_r = x / 400 - 1;
			z_i = y / 400 - 1.2;
			while (i < 150 && z_r * z_r + z_i * z_i < 4)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i <= 149)
				mlx_pixel_put(env->p.mlx, env->p.win, x, y, 0x000F0F00 + i * 255 / 50);
			if (i == MAX_ITERATION)
				mlx_pixel_put(env->p.mlx, env->p.win, x, y, 0x00FFFFFF);
		}
	}
	return (0);
}




























