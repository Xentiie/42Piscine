/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:23:29 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/24 12:01:39 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr_write(long nb)
{
	char	c;

	if (nb >= 10)
	{
		ft_putnbr_write(nb / 10);
		ft_putnbr_write(nb % 10);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

void	ft_putnbr(int nb)
{
	long	nb_l;

	nb_l = (long)nb;
	if (nb_l == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb_l < 0)
	{
		write(1, "-", 1);
		nb_l = -nb_l;
	}
	ft_putnbr_write(nb_l);
}
