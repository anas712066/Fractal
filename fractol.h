/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:52:55 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/08 16:59:38 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FRACTOL_H
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
# define HIGHT 800

/*Complex value*/
typedef struct s_complex
{
	/*real*/
	double	x;
	/*imaginary*/
	double	y;
}	t_complex;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;/*mlx_init()*/
	void	*mlx_window;/*mlax_new_window*/
	/*Image*/
	t_img	img;
	/*Hooks member variable*/
}	t_fractal;

typedef struct s_img
{
	void	*imt_ptr;/*pointer to image struct*/
	char	*pixels_ptr;/*points to the actuals pixels*/
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

//**** String utils ***//
int		ft_strncmp(char *s1, char *s2, int n);
void	putstr_fd(char *s, int fd);

/*Init */
void	fractal_init(t_fractal *fractal);

/*math*/
double  map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);

#endif
