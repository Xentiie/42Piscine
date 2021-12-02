/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:27:06 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/28 17:31:51 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*add_sign(int sign, int nbr, int base_l, char *output);
char	*init_output(int nbr, int base_l, int sign);
void	ft_putnbr_base(int nbr, char *base, int base_l, char **output);

int	check_base(char *base, int *length)
{
	int		i;
	int		j;
	char	element_to_test;

	j = 0;
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == 42 || base[i] == 45)
			return (-1);
		element_to_test = base[i];
		j = 0;
		while (base[j] != '\0')
		{
			if (i != j && base[j] == element_to_test)
				return (-1);
			j++;
		}
		i++;
	}
	*length = i;
	return (1);
}

int	get_index_of(char *tab, char c)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	power(int x, int n)
{
	int	i;
	int	power;

	i = 0;
	power = 1;
	while (i < n)
	{
		power *= x;
		i++;
	}
	return (power);
}

int	ft_atoi_base(char *nbr, char *base, int base_l)
{
	int	i;
	int	value;
	int	p;

	p = 0;
	i = 0;
	value = 0;
	while (get_index_of(base, nbr[p + 1]) != -1)
		p++;
	while (get_index_of(base, nbr[i]) != -1)
	{
		if (get_index_of(base, nbr[i]) == -1)
			return (value);
		value += get_index_of(base, nbr[i]) * power(base_l, p);
		i++;
		p--;
	}
	return (value);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		negative;
	int		dec;
	int		basefrom_l;
	int		baseto_l;
	char	*output;

	negative = 1;
	if (!check_base(base_from, &basefrom_l) || !check_base(base_to, &baseto_l))
		return (NULL);
	if (basefrom_l <= 1 || baseto_l <= 1)
		return (NULL);
	while (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13))
		nbr++;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			negative = -negative;
		nbr++;
	}
	dec = ft_atoi_base(nbr, base_from, basefrom_l);
	output = init_output(dec, baseto_l, negative);
	ft_putnbr_base(dec * negative, base_to, baseto_l, &output);
	return (output);
}
