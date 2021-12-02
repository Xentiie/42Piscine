/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:46:11 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 21:25:45 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	get_total_length(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	total_length;

	total_length = 0;
	i = 0;
	while (sep[i++])
		total_length++;
	total_length = total_length * (size - 1);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j++])
			total_length++;
		i++;
	}
	return (total_length);
}

char	*ft_strcat(char *dest, char *src)
{
	int	isrc;
	int	idst;

	idst = 0;
	while (dest[idst] != '\0')
		idst++;
	isrc = 0;
	while (src[isrc] != '\0')
	{
		dest[idst] = src[isrc];
		isrc++;
		idst++;
	}
	dest[idst] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_length;
	int		i;
	char	*dst;

	if (size <= 0)
	{
		dst = malloc(sizeof(char));
		*dst = 0;
		return (dst);
	}
	total_length = get_total_length(size, strs, sep);
	dst = malloc(sizeof(char) * (total_length));
	if (dst == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		ft_strcat(dst, strs[i]);
		if (i < size - 1)
			ft_strcat(dst, sep);
		i++;
	}
	return (dst);
}
