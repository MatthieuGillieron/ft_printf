/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noyau.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mg <mg@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:11:10 by mg                #+#    #+#             */
/*   Updated: 2024/09/26 19:25:11 by mg               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_string(const char *type, va_list ap)
{
	int	i;
	int avance;

	i = 0;
	while (type[i])
	{
		if (type[i] == '%' && type[i + 1])
		{
			avance = ft_type_trouver(&type[i + 1], ap); // Passer après '%'
			i += avance;  // Avancer du nombre de caractères retourné
		}
		else
		{
			ft_putchar(type[i]);  // Afficher les caractères normaux
			i++;
		}
	}
}

int	ft_type_trouver(const char *type, va_list ap)
{
	// Pas besoin de gérer explicitement le '%' ici, car on passe déjà `&type[i + 1]`
	if (*type == '%')
		ft_print_char('%');  // Affiche un pourcentage littéral
	else if (*type == 'c')
		ft_print_char(va_arg(ap, int));  // Gérer un caractère
	else if (*type == 's')
		ft_print_str(va_arg(ap, char *));  // Gérer une chaîne de caractères
	else if (*type == 'd' || *type == 'i')
		ft_print_digit(va_arg(ap, int));  // Gérer un entier (signed)
	else
		return 0;  // Aucun spécificateur trouvé

	return 1;  // On retourne 1 pour avancer après le spécificateur
}

int ft_printf(const char *format, ...)
{
    va_list ap;  // Créer une liste d'arguments variadiques
    va_start(ap, format);  // Initialiser la liste avec les arguments qui suivent 'format'

    // Appeler la fonction de parsing (parcourt le format et affiche chaque argument)
    ft_check_string(format, ap);
    
    va_end(ap);  // Terminer l'utilisation des arguments variadiques
    return 0;  // Pour l'instant, on retourne 0, mais on pourrait retourner le nombre de caractères imprimés par exemple.
}