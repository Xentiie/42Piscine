/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:11:58 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/26 14:45:51 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	i;
	int	counter;
	int	*output;

	i = 0;
	size = max - min;
	if (size <= 0)
		return (NULL);
	output = malloc(sizeof(int) * size + 1);
	if (output == NULL)
		return (NULL);
	counter = min;
	while (i < size)
	{
		output[i] = counter;
		counter++;
		i++;
	}
	return (output);
}
