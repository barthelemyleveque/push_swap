/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 10:52:49 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/25 16:51:42 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
** Error = 0 : tout ce qui est erruer de formatage, commande, duplicate, int..
** Error = 1 : quand c'est pas trie cheh
*/

int		ft_print_checker_errors(int error, t_main *master, t_cmds *tab_cmds)
{
	if (error == 0)
	{
		ft_printf("Error\n");
		free_checker(master, tab_cmds);
		return (0);
	}
	if (error == -1)
	{
		ft_printf("KO\n");
		free_checker(master, tab_cmds);
		return (0);
	}
	return (0);
}

int		ft_print_swap_errors(int error, t_main *master)
{
	if (error == 0)
	{
		ft_printf("Error\n");
		free_swap(master);
		return (0);
	}
	if (error == -1)
	{
		ft_printf("KO\n");
		free_swap(master);
		return (0);
	}
	if (error == -2)
		free(master);
	return (0);
}

int		ft_error_tab(int err, char ***tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			free(tab[i][j]);
		free(tab[i]);
	}
	free(tab);
	if (err == 0)
	{
		ft_printf("Error\n");
		return (-2);
	}
	return (0);
}

int		*ft_duplicates(int *tab_i, int count)
{
	int	i;
	int	c;

	i = -1;
	while (++i < count)
	{
		c = i;
		while (++c <= count)
		{
			if (tab_i[i] == tab_i[c])
			{
				free(tab_i);
				return (NULL);
			}
		}
	}
	return (tab_i);
}

int		ft_definitely_sorted(t_main *master)
{
	t_stack		*stack_a;

	stack_a = master->a;
	if (master->b->nb)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->nb->val > stack_a->next->nb->val)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
