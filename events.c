/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:58:27 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/24 12:59:38 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
			fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
			fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += 0.5;
	else if (keysym == XK_Right)
		fractal->shift_x -= 0.5;
	else if (keysym == XK_Up)
		fractal->shift_y -= 0.5;
	else if (keysym == XK_Down)
		fractal->shift_y += 0.5;
	/*else if (keysym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
		fractal->iterations_definition -= 10;*/
	fractal_render(fractal);
	return (0);
}
