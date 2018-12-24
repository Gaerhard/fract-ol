/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_graph.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:07:44 by gaerhard          #+#    #+#             */
/*   Updated: 2018/12/24 14:14:04 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_GRAPH_H
# define LIB_GRAPH_H
# include "mlx.h"
# define WIDTH 1080
# define HEIGHT 960

typedef struct	s_mlx
{
	void	*win;
	void	*mlx;
}				t_mlx;

typedef struct	s_img
{
	void	*ptr;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}				t_img;

typedef struct	s_env
{
	t_img	img;
	t_mlx	p;
}				t_env;

int			key_press(int key, t_env *env);
int			mouse_press(int button, int x, int y, t_env *env);
int			mlx_close(t_env *env);

#endif
