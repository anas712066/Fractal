/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:58:27 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/24 21:59:48 by mumajeed         ###   ########.fr       */
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
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
	{
		if (fractal->iterations_definition > 10)
			fractal->iterations_definition -= 10;
	}
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (!fractal)
		return (1);

	(void)x;
	(void)y;

	if (button == Button5)
		fractal->zoom *= 0.95;
	else if (button == Button4)
		fractal->zoom *= 1.05;
	if (fractal->zoom < 0.01)
		fractal->zoom = 0.01;
	else if (fractal->zoom > 100)
		fractal->zoom = 100;
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	double	new_julia_x, new_julia_y;
	t_range x_range, y_range, pixel_x_range, pixel_y_range;

	x_range.min = -2.0; x_range.max = 2.0;
	y_range.min = 2.0; y_range.max = -2.0;
	pixel_x_range.min = 0; pixel_x_range.max = WIDTH;
	pixel_y_range.min = 0; pixel_y_range.max = HEIGHT;

	new_julia_x = map(x, x_range, pixel_x_range);
	new_julia_y = map(y, y_range, pixel_y_range);

	// Solo renderiza si los valores cambiaron
	if (new_julia_x != fractal->julia_x || new_julia_y != fractal->julia_y)
	{
		fractal->julia_x = new_julia_x;
		fractal->julia_y = new_julia_y;
		fractal_render(fractal);
	}

	return 0;
}
