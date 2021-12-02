/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:31:29 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 11:49:10 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "map.h"
#include "ft.h"

void	read_first_line(int fd);
void	parse_line(char *line, t_point *out_p, int y_index);

static int		g_y_max;
static int		g_x_max;
static char		g_rock;
static char		g_empty;
static char		g_full;
static int		g_error;
static int		g_rockcounter;

char	*ft_read_until(int fd, char c)
{
	char	*buff;
	char	*tmp;
	char	*input;
	int		len;

	buff = malloc(sizeof(*buff));
	input = malloc(sizeof(*input));
	if (!buff || !input)
		return (0);
	input[0] = '\0';
	len = 0;
	while (read(fd, buff, 1) > 0 && *buff != c)
	{
		len++;
		tmp = input;
		input = malloc(sizeof(*input) * (++len + 1));
		if (!input)
			return (0);
		input[0] = '\0';
		ft_strcat(input, tmp);
		ft_strncat(input, buff, 1);
		free(tmp);
	}
	input[len] = '\0';
	return (input);
}

t_point	*parse_file(int fd)
{
	char	*current_line;
	int		y;
	t_point	*output;

	g_rockcounter = 0;
	read_first_line(fd);
	current_line = ft_read_until(fd, '\n');
	g_x_max = ft_strlen(current_line);
	output = malloc(sizeof(t_point) * g_x_max * g_y_max);
	parse_line(current_line, output, 0);
	y = 1;
	while (y < g_y_max)
	{
		current_line = ft_read_until(fd, '\n');
		parse_line(current_line, output, y);
		y++;
	}
	return (output);
}

void	parse_line(char *line, t_point *out_p, int y_index)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == g_empty)
		{
			out_p[i + g_x_max * y_index] = (t_point){
				.x = i, .y = y_index, .dist = 0, .is_rock = 0
			};
			i++;
		}
		else if (line[i] == g_rock)
		{
			out_p[i + g_x_max * y_index] = (t_point){
				.x = i, .y = y_index, .dist = 0, .is_rock = 1
			};
			g_rockcounter++;
			i++;
		}
		else
			g_error = 1;
	}
}

void	read_first_line(int fd)
{
	char	*curr_line;
	int		line_l;

	curr_line = ft_read_until(fd, '\n');
	line_l = ft_strlen(curr_line);
	g_empty = curr_line[line_l - 3];
	g_rock = curr_line[line_l - 2];
	g_full = curr_line[line_l - 1];
	curr_line[line_l - 3] = '\0';
	g_y_max = ft_atoi(curr_line);
}

const void	*get_var(int var_id)
{
	const void	*vars[7] = {
		(void *)&g_y_max, (void *)&g_x_max,
		(void *)&g_rock, (void *)&g_empty,
		(void *)&g_full, (void *)&g_error,
		(void *)&g_rockcounter
	};

	return (vars[var_id]);
}
