/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:37:53 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/18 14:36:50 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	index;
	int	tab_end;
	int	swap;

	index = 0;
	tab_end = (size - 1);
	while (index < tab_end)
	{
		swap = tab[index];
		tab[index] = tab[tab_end];
		tab[tab_end] = swap;
		index++;
		tab_end--;
	}
}
