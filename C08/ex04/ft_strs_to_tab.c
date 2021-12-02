/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 21:00:30 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 16:36:44 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

struct s_stock_str	ft_str_to_tab(char *str)
{
	char				*cpy;
	struct s_stock_str	stock_str;
	int					size;

	size = ft_strlen(str);
	cpy = malloc(sizeof(char) * (size + 1));
	cpy = ft_strcpy(cpy, str);
	stock_str = (struct s_stock_str){.size = size, .str = str, .copy = cpy};
	return (stock_str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char**av)
{
	int					i;
	struct s_stock_str	*output;

	i = 0;
	output = (struct s_stock_str *)malloc(
			sizeof(struct s_stock_str) * (ac + 1));
	while (i < ac)
	{
		output[i] = ft_str_to_tab(av[i]);
		i++;
	}
	output[i] = (struct s_stock_str){.str = 0};
	return (output);
}
