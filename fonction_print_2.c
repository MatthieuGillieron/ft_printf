/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_print_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:10:05 by mg                #+#    #+#             */
/*   Updated: 2024/09/26 19:36:09 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int nb)
{
	if (nb > 9)
		ft_print_unsigned(nb / 10);
	ft_putchar((nb % 10) + '0');
}


void ft_print_adresse(void *ptr)
{
	unsigned long adresse = (unsigned long)ptr;
	ft_putstr_opti("0x");
	ft_print_hex_min(adresse);
}