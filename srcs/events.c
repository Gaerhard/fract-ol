/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:23:41 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/10 14:02:56 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mlx_close(char *str, int fd, t_env *env)
{
	free_all(str, fd, env);
	exit(0);
}

void	redraw(t_env *env)
{
	if (env->fractal == JULIA)
		set_julia_thread(env);
	else if (env->fractal == MANDELBROT)
		set_mandel_thread(env);
	else if (env->fractal == BURNING_SHIP)
		set_ship_thread(env);
	else if (env->fractal == MANDEL_2)
		set_mandel2_thread(env);
}

int		key_press(int key, t_env *env)
{
	if (key == 53)
		mlx_close("exiting frat-ol", 1, env);
	if ((key == 36) && env->fractal == JULIA)
		env->modify *= -1;
	if (key == 15 || key == 5 || key == 11)
		manual_color(key, env);
	if (key == 49)
	{
		if (env->fractal == JULIA)
			init_julia(env);
		else if (env->fractal == MANDELBROT)
			init_mandel(env);
		else if (env->fractal == BURNING_SHIP)
			init_ship(env);
		else if (env->fractal == MANDEL_2)
			init_mandel2(env);
		redraw(env);
	}
	if (key == 18 || key == 19 || key == 20 || key == 21)
		apply_color(key, env);
	return (key_press_2(key, env));
}

int		mouse_press(int button, int x, int y, t_env *env)
{
	if (button == 1 || button == 4)
		zoom_in(x, y, env);
	else if (button == 2 || button == 5)
		zoom_out(x, y, env);
	redraw(env);
	return (0);
}

int		mouse_move(int x, int y, t_env *env)
{
	double delta;

	if (x > 0 && x < env->width && y > 4 && y < env->height && env->modify == 1)
	{
		delta = 3;
		env->c.r = -1 + delta / env->width * x;
		env->c.i = -1.2 + delta / env->height * y;
		mlx_clear_window(env->p.mlx, env->p.win);
		redraw(env);
	}
	return (0);
}
