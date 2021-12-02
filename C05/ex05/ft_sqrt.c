/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:29:51 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/26 11:04:18 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	sqrt;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	i = 0;
	sqrt = 0;
	while (sqrt < nb && i < 46340)
	{
		i++;
		sqrt = i * i;
	}
	if (sqrt == nb)
		return (i);
	else
		return (0);
}
