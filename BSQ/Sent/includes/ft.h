/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reclaire <reclaire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:39:05 by reclaire          #+#    #+#             */
/*   Updated: 2021/12/01 11:58:32 by reclaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

char			*ft_strstr(char *str, char *to_find);
char			*ft_strncpy(char *dest, char *src, unsigned int n);
char			*ft_strncat(char *dest, char *src, unsigned int nb);
int				ft_strlen(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strdup(char *src);
char			*ft_strcpy(char *dest, char *src);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strcat(char *dest, char *src);
double			ft_sqrt(double n);
void			ft_putstr(char *str);
void			ft_putnbr(int nb);
void			ft_putchar(char c);
int				ft_atoi(char *str);
int				min(int a, int b);
int				max(int a, int b);
int				abs(int v);
#endif
