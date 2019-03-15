/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:29:02 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/14 18:13:39 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


/*
** ATTENTION :rajouter protection "+++" |  >int max < int min | duplicates
*/

int		*ft_convert_tab(char ***tab, int c, int	*count)
{
	int			i;
	long long	test;
	int			j;
	int			*tab_i;

	j = -1;
	*count = 0;
	while (++j < c && !(i = 0))
	{
		while (tab[j][i])
			i++;
		*count += i;
	}
	if (!(tab_i = (int*)malloc(sizeof(int) * *count)))
		return (NULL);
	j = -1;
	*count = -1;
	while (++j < c)
	{
		i = -1;
		while (tab[j][++i])
			tab_i[++(*count)] = (int)ft_atoi(tab[j][i]);
	}
	return (tab_i);
}

int		ft_check_tab(char ***tab, int c)
{
	int	j;
	int	i;
	int	l;

	j = -1;
	while (++j < c)
	{
		i = 0;
		while (tab[j][i])
		{
			l = -1;
			while (tab[j][i][++l] != '\0')
			{
				if ((tab[j][i][l] < '0' || tab[j][i][l] > '9') &&
					tab[j][i][l] != '-' && tab[j][i][l] != '+')
				{
					ft_printf("Error\n");
					return (0);
				}
			}
			i++;
		}
	}
	return (1);
}

char	***tab_char_init(int ac, char **av)
{
	char	***tab;
	int		i;
	int		c;

	i = 1;
	c = 0;
	if (!(tab = (char***)malloc(sizeof(char**) * ac)))
		return (0);
	while (i < ac)
	{
		if (!(tab[c] = ft_strsplit(av[i], ' ')))
			return (0);
		i++;
		c++;
	}
	tab[c] = NULL;
	return (tab);
}

void	print_tab(int *tab)
{
	int i;

	i = -1;
	printf("\n ---- \n");
	while (++i < 500)
		printf("tab[%d] : %d\n", i, tab[i]);
}

int		main(int ac, char **av)
{
	char	***tab;
	int		*tab_int;
	int		count;

	if (ac == 1)
		return (0);
	if (!(tab = tab_char_init(ac, av)))
		return (0);
	if (!(ft_check_tab(tab, ac - 1)))
		return (0);
	if (!(tab_int = ft_convert_tab(tab, ac - 1, &count)))
		return (0);
	// fonction assigner d'abord
	return (0);
}

