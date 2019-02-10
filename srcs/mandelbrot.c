/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 14:07:06 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/10 13:41:04 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc_mandel(t_env *e, double x, double y)
{
	double i;
	double tmp;
	double sqzr;
	double sqzi;

	i = 0;
	e->c.r = x / e->misc.zoom + e->misc.x1;
	e->c.i = y / e->misc.zoom + e->misc.y1;
	e->z.r = 0;
	e->z.i = 0;
	sqzr = e->z.r * e->z.r;
	sqzi = e->z.i * e->z.i;
	while (i < e->misc.max_iteration && sqzr + sqzi < 4)
	{
		tmp = e->z.r;
		e->z.r = sqzr - sqzi + e->c.r;
		e->z.i = 2 * e->z.i * tmp + e->c.i;
		sqzr = e->z.r * e->z.r;
		sqzi = e->z.i * e->z.i;
		i++;
	}
	e->img.data[(int)y * e->width + (int)x] = color(i, e);
}

static void	*mandel(void *env)
{
	double	x;
	double	y;
	t_env	*data;

	data = (t_env *)env;
	y = data->thr_data.pos - 1;
	while (++y < data->thr_data.pos + data->thr_data.length)
	{
		x = -1;
		while (++x < data->width)
			calc_mandel(data, x, y);
	}
	return (0);
}

void		set_mandel_thread(t_env *e)
{
	pthread_t	thread[8];
	t_env		tab[8];
	int			i;

	i = -1;
	while (++i < 8)
	{
		ft_memcpy((void*)&tab[i], (void*)e, sizeof(t_env));
		tab[i].thr_data.pos = tab[i].thr_data.length * i;
		if (pthread_create(&thread[i], NULL, mandel, &tab[i]))
			mlx_close("failed to create thread", 2, e);
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(e->p.mlx, e->p.win, e->img.ptr, 0, 0);
}
