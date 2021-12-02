/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printsqr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:47:17 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 14:27:17 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "ft.h"
#include "solver.h"

void	print_symb(t_point current, t_point c1, t_point c2)
{
	char	c;

	c = *((char *)get_var(3));
	if (current.is_rock)
		c = *((char *)get_var(2));
	if (current.x >= c1.x && current.y >= c1.y)
		if (current.x <= c2.x && current.y <= c2.y)
			c = *((char *)get_var(4));
	write(1, &c, 1);
}

void	print_square(t_point c1, t_point c2, t_point *points)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < *((int *)get_var(1)))
	{
		x = 0;
		while (x < *((int *)get_var(0)))
		{
			print_symb(points[x + *((int *)get_var(0)) * y], c1, c2);
			x++;
		}
		y++;
		write(1, "\n", 1);
	}
}
