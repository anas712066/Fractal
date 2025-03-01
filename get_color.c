/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mumajeed <mumajeed@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:25:11 by mumajeed          #+#    #+#             */
/*   Updated: 2025/02/22 19:50:17 by mumajeed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iteration, int max_iterations, t_fractal *fractal)
{
	int	base_color;

	if (iteration >= max_iterations)
		return (0x000000); /* Negro */

	base_color = (iteration * fractal->color_shift) % 255;
	return ((base_color << 16) | (base_color << 8) | base_color);
}

