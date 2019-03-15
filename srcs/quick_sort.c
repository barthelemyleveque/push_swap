/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:55:31 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/14 17:14:27 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *tab, int a, int b)
{
	int	tmp;

	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
}

int		is_sort(int *tab, int end)
{
	int	i;

	i = -1;
	while (++i < end)
	{
		if (tab[i] > tab[i + 1])
			return (0);
	}
	return (1);
}

void	ft_quicksort(int *tab, int start, int end)
{
	int			gauche;
	int 		droite;
	int			pivot;
	int			c;

	c = 0;
	gauche = start - 1;
	droite = end + 1;
	pivot = tab[start];
	while (!(is_sort(tab, end)))
	{
		while (tab[--droite] > pivot)
			c++;
		while (tab[++gauche] < pivot)
			c++;
		if (gauche < droite)
			swap(tab, gauche, droite);
		else 
			break;
	}
	if (!(is_sort(tab, end)))
	{
		ft_quicksort(tab, start, droite);
		ft_quicksort(tab, droite + 1, end);
	}
}

