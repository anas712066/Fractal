/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:52:55 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/22 19:50:39 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define ERROR_MESSAGE "Please enter \n\t\" \
./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"

# define WIDTH 800
# define HEIGHT 800

/*
 * COLORS
*/
# define BLACK	0x000000/*RGB(0, 0, 0)*/
# define WHITE	0xFFFFFF/*RGB(255, 255, 255)*/
# define RED	0xFF0000/*RGB(255, 0, 0)*/
# define GREEN	0x00FF00/*RGB(0, 255, 0)*/
# define BLUE	0x0000FF/*RGB(0, 0, 255)*/

/*Psychedelic colors*/
# define MAGENTA_BURST	0xFF00FF/*A vibrant magenta*/
# define LIME_SHOCK	0xCCFF00/*A blinding lime*/
# define NEON_ORANGE	0xFF6600/*A blazing neon orange*/
# define PSYCHEDELIC_PURPLE	0x660066/*A deep purple*/
# define AQUA_DREAM	0x33CCCC/*A bright turquoise*/
# define HOT_PINK	0xFF66B2/*As the name suggests!*/
# define ELECTRIC_BLUE	0x0066FF/*A radiant blue*/
# define LAVA_RED	0xFF3300/*A bright, molten red*/

/*Complex value*/
typedef struct s_complex
{
	/*real*/
	double	x;
	/*imaginary*/
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;/*pointer to image struct*/
	char	*pixels_ptr; /*points to the actuals pixels*/
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;



typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;/*mlx_init()*/
	void	*mlx_window;/*mlax_new_window*/
	/*Image*/
	t_img	img;
	/*Hooks member variable*/
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
}	t_fractal;

//**** String utils ***//
int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *s, int fd);

/*Init */
void		fractal_init(t_fractal *fractal);

/*math for scaling pixels on my screen resolution*/
typedef struct s_range
{
	double	min;
	double	max;
}	t_range;

typedef struct s_limits
{
	t_range	new_limits;
	t_range	old_limits;
	t_range	old_limits_windows;
}	t_limits;

typedef struct s_pixel_data
{
	t_complex	z;
	t_complex	c;
	t_limits	limits;
}	t_pixel_data;

typedef struct s_color_range
{
	t_range	color_range;
	t_range	iteration_range;
}	t_color_range;

double		map(double n, t_range new_range, t_range old_range);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

/*render*/
void		fractal_render(t_fractal *fractal);
//void		handle_pixel(int x, int y, t_fractal *fractal);
int			get_color(int iteration, int max_iterations);
void		fractal_render(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int		close_handler(t_fractal *fractal);

#endif
