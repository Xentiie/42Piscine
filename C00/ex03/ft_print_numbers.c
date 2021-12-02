/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:20:40 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/10 22:00:52 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	char	c;
	int		i;

	i = 0;
	while (i <= 9)
	{
		c = i + '0';
		write(1, &c, 1);
		i++;
	}
}
