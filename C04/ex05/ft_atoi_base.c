/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:23:29 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/28 13:10:09 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (i);
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

void	init_vars(int *i, int *p, int *value, char **str)
{
	*p = 0;
	*i = 0;
	while ((*str)[(*i)++] != '\0')
	{
		(*p)++;
	}
	*i = 0;
	*p -= 1;
	*value = 0;
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_length;
	int	i;
	int	p;
	int	value;
	int	factor;

	base_length = check_base(base);
	if (base_length <= 1)
		return (0);
	init_vars(&i, &p, &value, &str);
	factor = 1;
	if (str[0] == '-')
		factor *= -1;
	while (str[i] != '\0')
	{
		if (get_index_of(base, str[i]) == -1)
			return (value * factor);
		value += get_index_of(base, str[i]) * power(base_length, p);
		i++;
		p--;
	}
	return (value * factor);
}
