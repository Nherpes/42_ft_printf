/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:00:05 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/19 15:02:43 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

size_t	ft_formatchr(va_list arg_ptr, char format)
{
	size_t	n;

	n = 0;
	if(format == 'c')
		n = ft_putchar(va_arg(arg_ptr, int));
	else if(format == 's')
		n = ft_putstr(va_arg(arg_ptr, char *));
	else if(format == 'p')
		write(1, "P", 1); //missing function
	else if(format == 'd' || format == 'i')
		n = ft_putnbr(va_arg(arg_ptr, int));
	else if(format == 'u')
		n = ft_putunbr(va_arg(arg_ptr, unsigned int));
	else if(format == 'x' || format == 'X')
		n = ft_puthex(va_arg(arg_ptr, unsigned int), format);
	else if(format == '%')
		write(1, "%", 1);
	return (n); //add the number of extra characters diplayed 
}

int	ft_printf(const char *arg_str, ...)
{
	va_list arg_ptr;
	size_t	i;
	size_t	count;

	va_start(arg_ptr, arg_str);
	count = 0;
	i = 0;
	while(arg_str[i])
	{
		if(arg_str[i] == '%')
		{
			count += ft_formatchr(arg_ptr, *ft_strchr("cspdiuxX%", arg_str[i + 1]));
			i += 2;
		} 
		else
		{
			ft_putchar(arg_str[i]);
			count++;
			i += 1;
		}
	}
	va_end(arg_ptr);
	return (count);
}
//c - char
//s - string
//p - pointer
//d & i - signed decimal interger
//u - unsigned decimal interger
//x - unsinged decimal interger 
//X - unsinged decimal interger Uppercase
//
//add arg connection
//check for args being null & compare w/ printf


int	main(void)
{
	ft_printf("I am %s, and these are the value I believe in:%% %d, %x, %X, %i, %c\n", "David", 1, 15, 15, 9000, 'a');
	printf("I am %s, and these are the value I believe in:%% %d, %x, %X, %i, %c\n", "David", 1, 15, 15, 9000, 'a');
}
