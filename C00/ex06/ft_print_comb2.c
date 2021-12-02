/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:07:39 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/13 10:08:20 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	to_write[5];

	i = 0;
	j = 1;
	while (i <= 99)
	{
		while (j <= 99)
		{
			to_write[0] = ((i - (i % 10)) / 10) + '0';
			to_write[1] = (i % 10) + '0';
			to_write[2] = ' ';
			to_write[3] = ((j - (j % 10)) / 10) + '0';
			to_write[4] = (j % 10) + '0';
			write(1, &to_write, 5);
			if (!(i == 98 && j == 99))
				write(1, ", ", 2);
			j++;
		}
		i++;
		j = i + 1;
	}
}
