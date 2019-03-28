/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:29:02 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/26 17:52:43 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		*ft_convert_tab(char ***tab, int c, int *count, int j)
{
	int			i;
	int			*tab_i;

	*count = 0;
	while (++j < c && !(i = 0))
	{
		while (tab[j][i])
			i++;
		*count += i;
	}
	if (!(*count) || !(tab_i = (int*)malloc(sizeof(int) * *count)))
		return (NULL);
	j = -1;
	*count = -1;
	while (++j < c && (i = -1))
		while (tab[j][++i])
		{
			tab_i[++(*count)] = (int)ft_atoi(tab[j][i]);
			if (ft_strlen(tab[j][i]) > 11 || ft_atol(tab[j][i]) > INT_MAX ||
				ft_atol(tab[j][i]) < INT_MIN || ft_strlen(tab[j][i]) == 0
				|| (ft_strlen(tab[j][i]) > 1 && tab_i[(*count)] == 0))
				return (ft_free_long_tab(tab_i));
		}
	return (ft_duplicates(tab_i, *count));
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
					return (0);
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
	if (av[1][0] == '\0')
		return (0);
	if (!(ft_strcmp(av[1], "-v")))
		i++;
	if (!(tab = (char***)malloc(sizeof(char**) * ac)))
		return (0);
	while (i < ac)
	{
		tab[c] = NULL;
		if (!(tab[c] = ft_strsplit(av[i], ' ')))
			return (0);
		i++;
		c++;
	}
	tab[c] = NULL;
	return (tab);
}

int		start_tab(int ac, char **av, t_main *master)
{
	char	***tab;
	int		*tab_int;
	int		count;
	int		v;

	if (ac == 1)
		return (0);
	v = (!(ft_strcmp(av[1], "-v"))) ? 1 : 0;
	if (!(tab = tab_char_init(ac, av)))
		return (-4);
	if (!(ft_check_tab(tab, ac - 1 - v)))
		return (ft_error_tab(0, tab));
	if (!(tab_int = ft_convert_tab(tab, ac - 1 - v, &count, -1)))
		return (ft_error_tab_int(0, tab, tab_int));
	if (!(init_master(tab_int, count, master)))
		return (0);
	ft_error_tab_int(2, tab, tab_int);
	return (1);
}
