/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:35:23 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/21 13:35:28 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int				ft_printf(const char *arg_str, ...);
size_t			ft_strlen(const char *str);
char			*ft_strchr(const char *str, int c);
unsigned int	ft_putchar(char c);
unsigned int	ft_putnbr(int nbr);
unsigned int	ft_putunbr(unsigned int nbr);
unsigned int	ft_putstr(char *str);
unsigned int	ft_puthex(unsigned int to_hex, char xcase);
unsigned int	ft_putptr(unsigned long long to_hex);
void			*ft_calloc(size_t nmemb, size_t size);

#endif
