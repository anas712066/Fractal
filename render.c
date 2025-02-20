/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:34:57 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/18 21:42:37 by mumajeed         ###   ########.fr       */
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



void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_pixel_data	data;
	int		i;
	int		color;

	i = 0;
	data.z.x = 0.0;
	data.z.y = 0.0;

	data.limits.new_limits.min = -2.0;
	data.limits.new_limits.max = 2.0;
	data.limits.old_limits.min = 0;
	data.limits.old_limits.max = WIDTH;
	data.limits.old_limits_windows.min = 0;
	data.limits.old_limits_windows.max = HEIGHT;

//	(void) fractal;/*Borrar este casteo ya que lo necesito cambiarlo luego*/
	data.c.x = map(x, data.limits.new_limits, data.limits.old_limits);
	data.c.y = map(y, data.limits.new_limits, data.limits.old_limits_windows);

	while (i < fractal->iterations_definition)
	{
		data.z = sum_complex(square_complex(z), c);
		if ((data.z.x * data.z.x) + (data.z.y * data.z.y) > fractal->escape_value)
			break;
		i++;
	}
	color = get_color(i, fractal->iterations_definitions);
	my_pixel_put(x, y, color);
}/*
		{
			color = get_color(i, fractal->iterations_definitions);
			my_pixel_put(x, y, color);
			return ;
		}
*/
void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
}
