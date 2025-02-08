/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 23:34:57 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/08 23:34:57 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    handle_pixel(int x, int y, t_fractal *fractal)
{
        t_complex z;
        t_complex c;

        /*1º iteration*/
        z.x = 0.0;
        z.y = 0.0;

        c.x = map(x, -2, +2, 0, WIDTH);/*unscaled_num, new_min, new_max, old_min, old_max*/
        c.y = map(y, +2, -2, 0, HEIGHT);/*unscaled_num, new_min, new_max_ old_min, old_max*/
}

void    fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            handel_pixel(fractal, x, y);
        }
    }
}