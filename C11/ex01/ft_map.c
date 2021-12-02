/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:41:40 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/02 13:18:07 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*output;

	i = 0;
	output = malloc(sizeof(int) * length);
	while (i < length)
	{
		output[i] = (*f)(tab[i]);
		i++;
	}
	return (output);
}
