/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 20:50:15 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 20:50:17 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_word(char *str, char *charset);
int		ft_is_sep(char *str, char *charset);
int		ft_word_length(char *str, char *charset);
void	ft_strcpy_revers(char *dest, char *str, int index);

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		word_l;
	int		c_word;
	char	**dest;

	i = 0;
	c_word = ft_count_word(str, charset);
	dest = malloc(sizeof(*dest) * (c_word + 1));
	if (dest == NULL)
		return (NULL);
	while (i < c_word)
	{
		while (*str && ft_is_sep(str, charset))
			str++;
		word_l = ft_word_length(str, charset);
		dest[i] = malloc(sizeof(**dest) * (word_l + 1));
		if (dest[i] == NULL)
			return (NULL);
		ft_strcpy_revers(dest[i], str, word_l);
		str = str + word_l;
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && ft_is_sep(str, charset))
			str++;
		i = ft_word_length(str, charset);
		str = str + i;
		if (i)
			word++;
	}
	return (word);
}

int	ft_is_sep(char *str, char *charset)
{
	while (*charset != '\0')
	{
		if (*str == *charset)
			return (1);
		else
			charset++;
	}
	return (0);
}

int	ft_word_length(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && !(ft_is_sep(str + i, charset)))
	{
			i++;
	}
	return (i);
}

void	ft_strcpy_revers(char *dest, char *str, int index)
{
	dest[index] = '\0';
	index = index -1;
	while (index >= 0)
	{
		dest[index] = str[index];
		index = index - 1;
	}
}
