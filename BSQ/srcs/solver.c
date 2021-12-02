/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:29:38 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 14:37:10 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "map.h"
#include "ft.h"

t_point	ft_sort_point(int size, t_point tab[])
{
	int		i;
	t_point	current_best;

	current_best = (t_point){.x = 0, .y = 0, .dist = 0};
	i = 0;
	while (i < size)
	{
		if (tab[i].dist > current_best.dist)
		{
			current_best = tab[i];
		}
		i++;
	}
	return (current_best);
}

struct s_point	*ft_find_rock(t_point *point)
{
	const int	rockcount = *((int *)get_var(6));
	int			i;
	int			j;
	t_point		*rock_find;

	i = 0;
	j = 0;
	rock_find = (malloc(sizeof(t_point) * rockcount));
	while (i <= *((int *)get_var(0)) * *((int *)get_var(1)))
	{
		if ((point[i]).is_rock == 1)
		{
			rock_find[j] = point[i];
			j++;
		}
		i++;
	}
	return (rock_find);
}

t_point	ft_dist(t_point p1, t_point p2)
{
	int	d;

	d = (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
	p1.dist = min(p1.dist, d);
	if (p1.dist == d)
	{
		p1.closest_x = p2.x;
		p1.closest_y = p2.y;
	}
	return (p1);
}

void	ft_dist_to_border(t_point **input, int *i)
{
	(*input)[*i] = ft_dist((*input)[*i], (t_point){.x = (*input)[*i].x,
			.y = -1});
	(*input)[*i] = ft_dist((*input)[*i], (t_point){.x = (*input)[*i].x,
			.y = *((int *)get_var(1))});
	(*input)[*i] = ft_dist((*input)[*i], (t_point){.x = -1,
			.y = (*input)[*i].y});
	(*input)[*i] = ft_dist((*input)[*i], (t_point){.x = *((int *)get_var(0)),
			.y = (*input)[*i].y});
	(*i)++;
}

void	ft_compute_dists(t_point **input, t_point *rocks)
{
	const int	rockcount = *((int *)get_var(6));
	int			i;
	int			j;

	i = 0;
	while (i < (*((int *)get_var(0)) * *((int *)get_var(1))))
	{
		if ((*input)[i].is_rock)
		{
			(*input)[i].dist = 0;
			i++;
			continue ;
		}
		(*input)[i].dist = 2147483647;
		j = 0;
		while (j < rockcount)
		{
			(*input)[i] = ft_dist((*input)[i], rocks[j]);
			j++;
		}
		ft_dist_to_border(input, &i);
	}
}
