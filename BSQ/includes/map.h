/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:14:53 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 12:04:04 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_point
{
	int		x;
	int		y;
	int		dist;
	int		is_rock;
	int		closest_x;
	int		closest_y;
}	t_point;
const void	*get_var(int var_id);
t_point		*parse_file(int fd);
#endif