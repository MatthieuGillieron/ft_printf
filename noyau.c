/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noyau.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:11:10 by mg                #+#    #+#             */
/*   Updated: 2024/10/08 14:01:37 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_string(const char *type, va_list ap)
{
	int	i;
	int avance;
	int count_char;

	i = 0;
	count_char  = 0;
	while (type[i])
	{
		if (type[i] == '%' && type[i + 1])
		{
			avance = ft_type_trouver(&type[i + 1], ap);
			i += avance;
			count_char += avance; 
		}
		else
		{
			ft_putchar(type[i]);
			count_char++;
			i++;
		}
	}
	return (count_char);
}

int	ft_type_trouver(const char *type, va_list ap)
{
	if (*type == '%')
		ft_print_char('%');
	else if (*type == 'c')
		ft_print_char(va_arg(ap, int));
	else if (*type == 's')
		ft_print_str(va_arg(ap, char *));
	else if (*type == 'd' || *type == 'i')
		ft_print_digit(va_arg(ap, int));
	else if (*type == 'u')
		ft_print_unsigned(va_arg(ap, unsigned int));
	else if (*type == 'x')
		ft_print_hex_min(va_arg(ap, unsigned int));
	else if (*type == 'X')
		ft_print_hex_maj(va_arg(ap, unsigned int));
	else if (*type == 'p')
		ft_print_adresse(va_arg(ap, void *));
	else
		return 0;
	return 1;
} 


int ft_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
	int	count_char = 0;
    count_char = ft_check_string(format, ap);
    va_end(ap);
    return count_char;
}