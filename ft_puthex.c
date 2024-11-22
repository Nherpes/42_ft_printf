/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:54:27 by david-fe          #+#    #+#             */
/*   Updated: 2024/11/21 11:00:35 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned int	ft_hexcount(unsigned int to_count)
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

unsigned int	ft_puthex(unsigned int to_hex, char xcase)
{
	char			*hex_str;
	unsigned int	temp_num;
	unsigned int	i;

	if (!to_hex || !xcase)
		return(0);
	i = ft_hexcount(to_hex);
	hex_str = ft_calloc((i + 1), sizeof(char *));
	if (!hex_str)
		return(0);
	i--;
	if (to_hex == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (to_hex != 0)
	{
		temp_num = to_hex % 16;
		if (temp_num < 10)
			temp_num += '0';
		else if (xcase == 88)
			temp_num += 55;
		else if (xcase == 120)
			temp_num += 87;
		hex_str[i--] = temp_num;
		to_hex /= 16;
	}
	i = (unsigned int)ft_strlen(hex_str);
	ft_putstr(hex_str);
	free (hex_str);
	return (i);
}
/*
int	main(void)
{
	unsigned int	hex;
	hex = 12312312;
	ft_puthex(hex, 'x');
	printf("\n%X", hex);
	printf("\n%d", hex);
	//	printf("number of digits post conversion:\n%d\n", i);
}*/
