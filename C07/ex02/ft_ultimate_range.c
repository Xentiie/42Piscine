/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:28:32 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/23 12:09:07 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	counter;
	int	*output;

	size = max - min;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return (-1);
	i = 0;
	counter = min;
	while (i < size)
	{
		output[i] = counter;
		counter++;
		i++;
	}
	*range = output;
	return (size);
}
