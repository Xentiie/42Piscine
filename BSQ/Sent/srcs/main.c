/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:36:06 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 14:39:34 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "map.h"
#include "solver.h"
#include "ft.h"

void	solve(t_point *points)
{
	t_point	*rocks;
	int		square_size;
	t_point	*corners;
	t_point	center;

	corners = malloc(sizeof(*corners) * 2);
	rocks = ft_find_rock(points);
	ft_compute_dists(&points, rocks);
	center = ft_sort_point(*((int *)get_var(0)) * *((int *)get_var(1)), points);
	square_size = compute_square_size(center);
	compute_corners(center, square_size, &corners);
	print_square(corners[0], corners[1], points);
	free(corners);
}

void	solve_stdin(void)
{
	t_point	*points;

	points = parse_file(STDERR_FILENO);
	if (*((int *)get_var(5)) == 1)
	{
		write(1, "Map error\n", 10);
		return ;
	}
	solve(points);
}

int	main(int argc, char **argv)
{
	int		i;
	t_point	*points;

	i = 1;
	points = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			points = parse_file(open(argv[i], O_RDONLY));
			if (*((int *)get_var(5)) == 1)
			{
				write(1, "Map error\n", 10);
				continue ;
			}
			solve(points);
			i++;
		}
	}
	else
		solve_stdin();
}
