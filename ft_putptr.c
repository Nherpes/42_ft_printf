/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:41:50 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/23 20:15:50 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int	ft_ptrlen(unsigned int to_count)
{
	unsigned int	i;

	i = 0;
	while (to_count != 0)
	{
		to_count = to_count / 16;
		i++;
	}
	return (i);
}

char	*ft_fillptr(unsigned long long to_hex, char *hex_str, unsigned int i)
{
	unsigned int	temp_num;

	while (to_hex != 0)
	{
		temp_num = to_hex % 16;
		if (temp_num < 10)
			temp_num += '0';
		else 
			temp_num += 87;
		hex_str[i--] = temp_num;
		to_hex /= 16;
	}
	return (hex_str);
}

unsigned int	ft_putptr(unsigned long long to_hex)
{
	char			*hex_str;
	unsigned int	i;

	if (to_hex == 0)
		return (ft_putstr("(nil)"));
	i = ft_ptrlen(to_hex);
	hex_str = ft_calloc((i + 1), sizeof(char *));
	if (!hex_str)
		return (0);
	i--;
	hex_str = ft_fillptr(to_hex, hex_str, i);
	i = (unsigned int)ft_strlen(hex_str);
	i += ft_putstr("0x");
	ft_putstr(hex_str);
	free (hex_str);
	hex_str = NULL;
	return (i);
}
/*
int	main(void)
{
	unsigned long long hex = 12312312;
	unsigned long long *hex_ptr = &hex;
	printf("\n%p", hex_ptr);
	ft_putptr(hex_ptr);
	//	printf("number of digits post conversion:\n%d\n", i);
}*/
