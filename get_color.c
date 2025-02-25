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

int	get_color(int iteration, int max_iterations)
{
	t_color_range	ranges;

	if (iteration >= max_iterations)
		return (BLACK);

	ranges.color_range.min = BLACK;
	ranges.color_range.max = WHITE;
	ranges.iteration_range.min = 0;
	ranges.iteration_range.max = max_iterations;

	return (int)map(iteration, ranges.color_range, ranges.iteration_range);
}
