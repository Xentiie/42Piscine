/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 11:06:49 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/22 14:57:28 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	test_char(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

int	ft_str_is_uppercase(char *str)
{
	while (*str != '\0')
	{
		if (test_char(*str) != 1)
		{
			return (0);
		}
		str++;
	}
	return (1);
}
