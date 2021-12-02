/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:26:28 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/15 21:54:16 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size);

int	sort_int(int *a, int *b)
{
	return ((*a) - (*b));
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	*tab_end;
	int	*current_element;
	int	*element_to_sort;

	tab_end = (tab + size - 1);
	current_element = tab;
	while (current_element <= tab_end)
	{
		element_to_sort = current_element;
		while (element_to_sort <= tab_end)
		{
			if (sort_int(current_element, element_to_sort) > 0)
			{
				*current_element ^= *element_to_sort;
				*element_to_sort ^= *current_element;
				*current_element ^= *element_to_sort;
			}
			element_to_sort++;
		}
		current_element++;
	}
}
