/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:55:30 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/02 13:24:58 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	dir;
	int	i;

	i = 0;
	if (length == 0)
		return (1);
	while ((*f)(tab[i], tab[i + 1]) == 0 && i < length - 1)
		i++;
	if ((*f)(tab[i], tab[i + 1]) > 0)
	{
	}
}
