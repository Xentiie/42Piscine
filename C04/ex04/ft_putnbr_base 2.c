/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:23:29 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/19 15:11:50 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr_write(long nb, char *base, int base_size)
{
	if (nb >= base_size)
	{
		ft_putnbr_write(nb / base_size, base, base_size);
		ft_putnbr_write(nb % base_size, base, base_size);
	}
	else
	{
		write(1, &base[nb], 1);
	}
}

int	check_base(char *base)
{
	int		i;
	int		j;
	char	element_to_test;

	j = 0;
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == 42 || base[i] == 45)
			return (-1000);
		element_to_test = base[i];
		j = 0;
		while (base[j] != '\0')
		{
			if (i != j && base[j] == element_to_test)
				return (-1000);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nb, char *base)
{
	int		base_length;
	long	nb_l;

	nb_l = (long)nb;
	base_length = check_base(base);
	if (base_length <= 1)
		return ;
	if (nb_l < 0)
	{
		write(1, "-", 1);
		nb_l = -nb_l;
	}
	ft_putnbr_write(nb_l, base, base_length);
}
