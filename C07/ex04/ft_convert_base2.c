/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:28:30 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/28 20:39:47 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr_base2(long nbr_l, char *base, int base_l, char **output)
{
	int		i;
	int		j;
	int		nbr_final[100];

	i = 0;
	while (nbr_l)
	{
		nbr_final[i] = nbr_l % base_l;
		nbr_l = nbr_l / base_l;
		i++;
	}
	j = 0;
	while (--i >= 0)
	{
		(*output)[j] = base[nbr_final[i]];
		j++;
	}
}

void	ft_putnbr_base(int nbr, char *base, int base_l, char **output)
{
	int		i;
	long	nbr_l;
	int		is_neg;

	nbr_l = (long)nbr;
	is_neg = 0;
	i = 0;
	if (nbr_l < 0)
	{
		nbr_l = -nbr_l;
		**output = '-';
		(*output)++;
		is_neg = 1;
	}
	ft_putnbr_base2(nbr_l, base, base_l, output);
	if (is_neg)
		(*output)--;
}

char	*init_output(int nbr, int base_l, int sign)
{
	int		i;
	char	*output;

	i = 0;
	while (nbr)
	{
		nbr = nbr / base_l;
		i++;
	}
	if (sign > 0)
		output = malloc(sizeof(char) * i);
	else
		output = malloc(sizeof(char) * (i + 1));
	return (output);
}

char	*add_sign(int sign, int nbr, int base_l, char *output)
{
	int		i;
	char	*cpy;

	cpy = output;
	if (sign < 0)
	{
		i = 1;
		while (nbr)
		{
			output[i] = cpy[i + 1];
			cpy[0] = '-';
			i++;
			nbr /= base_l;
		}
	}
	return (cpy);
}
