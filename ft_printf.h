/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:15:53 by mg                #+#    #+#             */
/*   Updated: 2024/09/26 19:32:38 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void	ft_putchar(int c);
void	ft_putstr_opti(char *str);

void	ft_print_char(int c);
void	ft_print_str(char *str);
void	ft_print_digit(int nb);
void 	ft_print_hex_min(unsigned int num);
void 	ft_print_hex_maj(unsigned int num);
void	ft_print_unsigned(unsigned int nb);
void 	ft_print_adresse(void *ptr);

void	ft_check_string(const char *type, va_list ap);
int		ft_type_trouver(const char *type, va_list ap);
int 	myprintf(const char *format, ...);
int 	main();

