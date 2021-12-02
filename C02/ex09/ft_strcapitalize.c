/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:13:32 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/23 15:09:54 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str);

int	is_alpha(char c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

int	is_uppercase(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

int	is_numeric(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	index;
	int	uppercase_next_letter;

	index = 0;
	uppercase_next_letter = 1;
	while (str[index] != '\0')
	{
		if (is_alpha(str[index]))
		{
			if (uppercase_next_letter)
			{
				if (!is_uppercase(str[index]))
					str[index] -= 32;
				uppercase_next_letter = 0;
			}
			else if (is_uppercase(str[index]))
				str[index] += 32;
		}
		else if (is_numeric(str[index]))
			uppercase_next_letter = 0;
		else
			uppercase_next_letter = 1;
		index++;
	}
	return (str);
}
