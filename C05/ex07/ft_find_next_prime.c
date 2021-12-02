/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:41:16 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/25 11:07:12 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	sqrt;

	i = 1;
	sqrt = 0;
	while (sqrt < nb && i < 46340)
	{
		sqrt = i * i;
		i++;
	}
	return (i);
}

int	ft_find_next_prime(int nb)
{
	int	i;
	int	j;
	int	sqrt_v;

	if (nb <= 2)
		return (2);
	i = nb;
	j = 2;
	sqrt_v = ft_sqrt(nb);
	while (1)
	{
		while (j <= sqrt_v)
		{
			if (i % j == 0)
				break ;
			if (j == sqrt_v)
				return (i);
			j++;
		}
		j = 2;
		i++;
	}
	return (0);
}
