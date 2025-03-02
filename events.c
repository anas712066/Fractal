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

/*int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection,
			fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection,
			fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}*/

int	close_handler(t_fractal *fractal)
{
	if (fractal->img.img_ptr)
		mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	if (fractal->mlx_window)
		mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	if (fractal->mlx_connection)
	{
		mlx_destroy_display(fractal->mlx_connection);
		free(fractal->mlx_connection);
	}
	exit(EXIT_SUCCESS);
}


/*int	key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
        close_handler(fractal);
    else if (keysym == XK_Left)
        fractal->shift_x += (0.1 * fractal->zoom);
    else if (keysym == XK_Right)
        fractal->shift_x -= (0.1 * fractal->zoom);
    else if (keysym == XK_Up)
        fractal->shift_y -= (0.1 * fractal->zoom);
    else if (keysym == XK_Down)
        fractal->shift_y += (0.1 * fractal->zoom);
    else if (keysym == XK_j) // Activa/desactiva el cambio con el ratón
        fractal->allow_julia_change = !fractal->allow_julia_change;
    
    fractal_render(fractal);
    return (0);
}*/

/*int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (!fractal)
		return (1);

	(void)x;
	(void)y;
	if (button == Button1)
		fractal->allow_julia_change = !fractal->allow_julia_change;
	else if (button == Button5)
		fractal->zoom *= 0.95;
	else if (button == Button4)
		fractal->zoom *= 1.05;
	if (fractal->zoom < 0.01)
		fractal->zoom = 0.01;
	else if (fractal->zoom > 100)
		fractal->zoom = 100;
	fractal_render(fractal);
	return (0);
}*/

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	mouse_x = (x / (double)WIDTH) * 4 - 2;
	double	mouse_y = (y / (double)HEIGHT) * 4 - 2;

	if (button == Button1)
		fractal->allow_julia_change = !fractal->allow_julia_change;
	else if (button == Button5) // Zoom out
	{
		fractal->shift_x += (mouse_x - fractal->shift_x) * 0.05;
		fractal->shift_y += (mouse_y - fractal->shift_y) * 0.05;
		fractal->zoom /= 1.1;
	}
	else if (button == Button4) // Zoom in
	{
		fractal->shift_x -= (mouse_x - fractal->shift_x) * 0.05;
		fractal->shift_y -= (mouse_y - fractal->shift_y) * 0.05;
		fractal->zoom *= 1.1;
	}

	fractal_render(fractal);
	return (0);
}


int julia_track(int x, int y, t_fractal *fractal)
{
    double new_julia_x, new_julia_y;
    //t_range x_range, y_range;

    if (!fractal->allow_julia_change) // Si no está activado, no cambia
        return (0);

    //x_range.min = -2.0; x_range.max = 2.0;
    //y_range.min = 2.0; y_range.max = -2.0;
    //pixel_x_range.min = 0; pixel_x_range.max = WIDTH;
    //pixel_y_range.min = 0; pixel_y_range.max = HEIGHT;

	new_julia_x = (x / (double)WIDTH) * 4 - 2;
	new_julia_y = (y / (double)HEIGHT) * 4 - 2;




    if (new_julia_x != fractal->julia_x || new_julia_y != fractal->julia_y)
    {
        fractal->julia_x = new_julia_x;
        fractal->julia_y = new_julia_y;
        fractal_render(fractal);
    }

    return 0;
}

