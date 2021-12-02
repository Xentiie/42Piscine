/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:15:13 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/24 22:07:26 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex(unsigned char c)
{
	unsigned char	*hex;

	hex = "0123456789abcdef";
	if (c >= 16)
	{
		ft_puthex(c / 16);
		ft_puthex(c % 16);
	}
	else
	{
		write(1, &hex[c], 1);
	}
}

int	is_printable(unsigned char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if (is_printable(c))
			write(1, &c, 1);
		else
		{
			write(1, "\\", 1);
			if (c < 16)
				write(1, "0", 1);
			ft_puthex(c);
		}
		i++;
	}
}
