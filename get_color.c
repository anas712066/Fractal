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

int	get_color(int iter, int max_iter, t_fractal *fractal)
{
	int	base_color;

	if (iter >= max_iter)
		return (0x000000);
	base_color = (iter * fractal->color_shift) % 255;
	return ((base_color << 16) | (base_color << 8) | base_color);
}


