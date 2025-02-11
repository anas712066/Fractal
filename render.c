/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:34:57 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/11 21:28:02 by mumajeed         ###   ########.fr       */
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
	t_complex	z;
	t_complex	c;
	int		i;
	int		color;
	t_range		limits;

	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	limits.range_limits = {-2.0, 2.0};
	limits.old_limits = {0, WIDTH};
	limits.old_limts_windows = {0, HEIGHT};
	
//	(void) fractal;/*Borrar este casteo ya que lo necesito cambiarlo luego*/
	c.x = map(x, limits.range_limits, limits_old_limits);
	c.y = map(y, limits.range_limits, limits_old_limits_windows);

	while (i < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = (int)map(i, (t_range){BLACK, WHITE}),
					(t_range){0, fractal->iteratios_defintion});
			my_pixel_put();
			return ;
		}
	}
	
}

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
