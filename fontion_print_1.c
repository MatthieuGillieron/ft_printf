/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fontion_print_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:00:42 by mg                #+#    #+#             */
/*   Updated: 2024/10/03 09:06:38 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(int c)
{
	ft_putchar(c);
}




void	ft_print_str(char *str)
{
	int len;
	len = 0;
	while (str[len])
		len++;
	write (1, str, len);
}





void	ft_print_digit(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write (1, '-', 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}




void ft_print_hex_min(unsigned int num)
{
	if (num >= 16)
		ft_print_hex_lower(num / 16);
	int reste = num % 16;
	if (reste < 10)
		ft_putchar(reste + '0');
	else
		ft_putchar(reste - 10 + 'a');
}




void ft_print_hex_maj(unsigned int num)
{
	if (num >= 16)
		ft_print_hex_maj(num / 16);
	int reste = num % 16;
	if (reste < 10)
		ft_putchar(reste + '0');
	else
		ft_putchar(reste - 10 + 'A');
}