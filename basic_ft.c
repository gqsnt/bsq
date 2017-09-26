#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i = i + 1;
	}
}

int     ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i = i + 1;
	return (i);
}

int		ft_atoi(const char *str)
{
	int i;
	int nbr;
	int negative;

	nbr = 0;
	negative = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
			(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		negative = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (negative == 1)
		return (-nbr);
	else
		return (nbr);
}

char **malloc_tab(char **tab, t_coor max)
{
	int i;

	i = 0;
	tab = malloc((max.y + 1) * sizeof(char *));
	while(i < max.y)
	{
		tab[i] = malloc((max.x + 1) * sizeof(char));
		i = i + 1;
	}
	return (tab);
}
