/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estarck <estarck@student.42mulhous>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:24:07 by estarck           #+#    #+#             */
/*   Updated: 2021/11/19 15:00:32 by estarck          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	int	istr;
	int	ifind;
	int	xfind;

	istr = 0;
	ifind = 0;
	if ((to_find[ifind]) == '\0')
		return (&str[istr]);
	while (str[istr] != '\0')
	{
		if (str[istr] == to_find[ifind])
		{
			xfind = istr;
			while (str[istr++] == to_find[ifind++])
			{
				if (to_find[ifind] == '\0')
					return (&str[xfind]);
			}
			istr = xfind;
			ifind = 0;
		}
		istr++;
	}
	return (0x0);
}
