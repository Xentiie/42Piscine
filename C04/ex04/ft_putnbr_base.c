/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 18:49:28 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/27 20:18:55 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_base(char *base)
{
	int i;
	int z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr_base(int nbr, char *base)
{
	int     size_base;
	int     nbr_final[100];
	int     i;
	long    nbr_l;

	nbr_l = (long)nbr;
	i = 0;
	size_base = 0;
	if (check_base(base))
	{
		if (nbr_l < 0)
		{
			nbr_l = -nbr_l;
			write(1, "-", 1);
		}
		while (base[size_base])
			size_base++;
		while (nbr_l)
		{
			nbr_final[i] = nbr_l % size_base;
			nbr_l = nbr_l / size_base;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nbr_final[i]]);
	}
}