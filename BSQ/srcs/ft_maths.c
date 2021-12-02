/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:34:30 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 12:38:15 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

double	ft_sqrt(double nb)
{
	double	i;
	double	sqrt;

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
	return (i);
}

int	abs(int v)
{
	if (v < 0)
		return (-v);
	else
		return (v);
}
