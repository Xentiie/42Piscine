/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computesquare.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:36:11 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 14:26:03 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"
#include "ft.h"
#include "solver.h"

int	compute_square_size(t_point centre)
{
	int	square_size;

	square_size = max(
			abs(centre.x - centre.closest_x),
			abs(centre.y - centre.closest_y));
	return (square_size - 1);
}

void	compute_corners(t_point centre, int square_size, t_point **output)
{
	(*output)[0] = (t_point){.x = centre.x - square_size,
		.y = centre.y - square_size};
	(*output)[1] = (t_point){.x = centre.x + square_size,
		.y = centre.y + square_size};
}
