/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 13:20:02 by gaerhard          #+#    #+#             */
/*   Updated: 2019/02/09 18:31:13 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define JULIA 0
# define MANDELBROT 1
# include "mlx.h"
# include <math.h>
# include "pthread.h"
# include "libft.h"

typedef struct			s_mlx
{
	void			*win;
	void			*mlx;
}						t_mlx;

typedef struct			s_img
{
	void			*ptr;
	int				*data;
	int				bpp;
	int				size_l;
	int				endian;
}						t_img;

typedef struct			s_compl
{
	double			i;
	double			r;
}						t_compl;

typedef struct			s_misc
{
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	unsigned long	zoom;
	double			max_iteration;
}						t_misc;

typedef struct			s_colors
{
	float red;
	float green;
	float blue;
}						t_colors;

typedef struct			s_threads
{
	int				length;
	int				pos;
}						t_threads;

typedef struct			s_env
{
	t_img			img;
	t_mlx			p;
	t_compl			c;
	t_compl			z;
	t_compl			init;
	t_misc			misc;
	t_threads		thr_data;
	t_colors		col;
	int				width;
	int				height;
	int				modify;
	int				fractal;
}						t_env;

void					init_mandel(t_env *env);
void					init_julia(t_env *env);
void					zoom_in(int mouse_x, int mouse_y, t_env *env);
void					zoom_out(int mouse_x, int mouse_y, t_env *env);
void					apply_color(int key, t_env *e);
int						key_press(int key, t_env *env);
int						mouse_press(int button, int x, int y, t_env *env);
int						mlx_close(t_env *env);
int						mouse_move(int x, int y, t_env *env);
int						set_mandel_thread(t_env *env);
int						set_julia_thread(t_env *env);
int						color(double iter, t_env *e);

#endif
