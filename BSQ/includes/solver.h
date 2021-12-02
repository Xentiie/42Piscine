/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 00:59:47 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 13:37:19 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVER_H
# define SOLVER_H
# include <stdlib.h>
# include "map.h"

t_point			ft_sort_point(int size, t_point tab[]);
struct s_point	*ft_find_rock(t_point *point);
int				ft_dist(t_point p1, t_point p2);
int				ft_dist_to_border(t_point **input, int i, int mdist);
void			ft_compute_dists(t_point **input, t_point *rocks);
void			compute_corners(t_point centre,
					int square_size, t_point **output);
int				compute_square_size(t_point centre);
void			print_square(t_point c1, t_point c2, t_point *points);
#endif