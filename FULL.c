
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>


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
		ft_print_digit(va_arg(ap, int));
	else if (*type == 'x')
    	ft_print_hex_min(va_arg(ap, unsigned int));
	else if (*type == 'X')
    	ft_print_hex_maj(va_arg(ap, unsigned int));
	else if (*type == 'u')
        ft_print_unsigned(va_arg(ap, unsigned int));
	else if (*type == 'p')
        ft_print_adresse(va_arg(ap, void *)); 
	else
		return 0;  // Aucun spécificateur trouvé

	return 1;  // On retourne 1 pour avancer après le spécificateur
}




int myprintf(const char *format, ...)
{
    va_list ap;  // Créer une liste d'arguments variadiques
    va_start(ap, format);  // Initialiser la liste avec les arguments qui suivent 'format'

    // Appeler la fonction de parsing (parcourt le format et affiche chaque argument)
    ft_check_string(format, ap);
    
    va_end(ap);  // Terminer l'utilisation des arguments variadiques
    return 0;  // Pour l'instant, on retourne 0, mais on pourrait retourner le nombre de caractères imprimés par exemple.
}

int main()
{
	printf("ceci est la vrai fonction");
	myprintf("ceci est ma fonction");
	
}