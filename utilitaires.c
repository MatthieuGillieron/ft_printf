/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaires.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:08:13 by mg                #+#    #+#             */
/*   Updated: 2024/09/26 19:25:27 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c) // int c -> pourquoi?
{
	write(1, &c, 1);
}

void	ft_putstr_opti(char *str)
{
	int	len;
	len= 0;
	while (str[len])
		len++;
	write (1, str, len);
}
