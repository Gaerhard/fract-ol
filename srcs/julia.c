/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:00:15 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/09 18:23:45 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	calc_julia(t_env *e, double x, double y)
{
	double i;
	double tmp;
	double sqzr;
	double sqzi;

	i = 0;
	e->z.r = x / e->misc.zoom + e->misc.x1;
	e->z.i = y / e->misc.zoom + e->misc.y1;
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

static void	*julia(void *env)
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
			calc_julia(data, x, y);
	}
	return (0);
}

int			set_julia_thread(t_env *e)
{
	pthread_t	thread[3];
	t_env		tab[3];
	int			i;

	i = -1;
	while (++i < 3)
	{
		ft_memcpy((void*)&tab[i], (void*)e, sizeof(t_env));
		tab[i].thr_data.pos = tab[i].thr_data.length * i;
		if (pthread_create(&thread[i], NULL, julia, &tab[i]))
			return (-1);
	}
	while (i--)
		pthread_join(thread[i], NULL);
	mlx_put_image_to_window(e->p.mlx, e->p.win, e->img.ptr, 0, 0);
	return (0);
}
