/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:47:49 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/25 21:33:30 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

/*int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) ||
		(ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		fractal.julia_x = atodbl(av[2]);
		fractal.julia_y = atodbl(av[3]);
		// Inicia la aplicación correctamente
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}*/
int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) ||
		(ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];

		/* Inicializar julia_x y julia_y solo si es julia */
if (!ft_strncmp(av[1], "julia", 5))
{
    if (ac == 4)
    {
        fractal.julia_x = atodbl(av[2]);
        fractal.julia_y = atodbl(av[3]);
    }
    else
    {
        fractal.julia_x = -0.7; // Valores por defecto
        fractal.julia_y = 0.27015;
    }
}

	else
	{
		fractal.julia_x = 0.0;
		fractal.julia_y = 0.0;
	}

		fractal_init(&fractal);
		fractal_render(&fractal);
		if (fractal.mlx_connection && fractal.mlx_window)
			mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
