/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42mulhou>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:27:25 by reclaire          #+#    #+#             */
/*   Updated: 2021/11/24 22:31:41 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*dec_to_hex(unsigned long n, int base)
{

	int	i = 12;
	int	j = 0;

	do{
		outbuf[i] = "0123456789ABCDEF"[num % base];
		i--;
		n = num/base;
	}while( num > 0);

	if(sign != ' '){
		outbuf[0] = sign;
		++j;
	}

	while( ++i < 13){
		outbuf[j++] = outbuf[i];
	}

	outbuf[j] = 0;
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int *a;
	printf("%s\n", (unsigned char *)a);
}

int main()
{
	ft_print_memory((void *)3, 10);
}
