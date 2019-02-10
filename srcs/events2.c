/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:13:23 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/10 14:02:16 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press_2(int key, t_env *e)
{
	double delta;
	double move;

	if (key == 123 || key == 124)
	{
		delta = fabs(e->misc.x2) + fabs(e->misc.x1);
		move = delta / e->misc.zoom * 2;
		e->misc.x1 += (key == 123) ? move : -move;
		e->misc.x2 += (key == 123) ? -move : move;
		redraw(e);
	}
	if (key == 125 || key == 126)
	{
		delta = fabs(e->misc.y2) + fabs(e->misc.y1);
		move = delta / e->misc.zoom * 2;
		e->misc.y1 += (key == 125) ? -move : move;
		e->misc.y2 += (key == 125) ? move : -move;
		redraw(e);
	}
	return (0);
}
