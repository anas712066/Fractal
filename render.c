/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:34:57 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/09 14:13:21 by mumajeed         ###   ########.fr       */
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
 *		MANDELBROT
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
	t_range		new_range;
	t_range		old_range;

	z.x = 0.0;
	z.y = 0.0;
	old_range.min = 0;
	old_range.max = 800;
	new_range.min = -2;
	new_range.max = 2;
	(void) fractal;/*Borrar este casteo ya que lo necesito cambiarlo luego*/
	c.x = map(x, new_range, old_range);
	c.y = map(y, new_range, old_range);
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
