/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:34:57 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/23 20:13:39 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * 						 ✅ map()
		   	0__________800   -2___________+2    
 *			|	   |	 |            | 
 *			|	   |	 |	      |	 
 *		800	|	   |	 |	      | 
 *			|	   |	 |	      | 
 *			|	   |  	 |	      | 
 *			|__________|     |____________|

 *	
 *		z = z^2 + c
 *		z initially is (0, 0)
 *		c is the actual point
 *
 *		z = z^2 + c -> z1 = c + c
 *
 *		JULIA
 *		./fractol julia <real> <i> 
 *		z = pixel_point + constant
*/
static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x + (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_pixel_data	data;
	int				i;
	int				color;

	i = 0;
	data.z.x = 0.0;
	data.z.y = 0.0;
	data.limits.new_limits.min = -2.0;
	data.limits.new_limits.max = 2.0;
	data.limits.old_limits.min = 0;
	data.limits.old_limits.max = WIDTH;
	data.limits.old_limits_windows.min = 0;
	data.limits.old_limits_windows.max = HEIGHT;
	data.c.x = map(x, data.limits.new_limits, data.limits.old_limits);
	data.c.y = map(y, data.limits.new_limits, data.limits.old_limits_windows);
	while (i < fractal->iterations_definition)
	{
		data.z = sum_complex(square_complex(data.z), data.c);
		if ((data.z.x * data.z.x) + (data.z.y * data.z.y)
			> fractal->escape_value)
		{
			color = get_color(i, fractal->iterations_definition);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, PSYCHEDELIC_PURPLE);
}

void	fractal_render(t_fractal *fractal)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connextion,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0, 0);
}
