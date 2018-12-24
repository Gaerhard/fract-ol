/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:23:41 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/24 13:44:11 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "lib_graph.h"
#include "libft.h"

int		mlx_close(t_env *env)
{
	(void)env;
	exit(0);
}

int		key_press(int key, t_env *env)
{
	(void)env;
	if (key == 53)
		mlx_close(env);
	return (0);
}
