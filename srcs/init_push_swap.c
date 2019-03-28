/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:12:51 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/26 17:50:21 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_swap_easy(t_main *master)
{
	master->f[0](master, 1);
	return (0);
}

int		ft_first_sort(t_main *master)
{
	int		med;
	int		count;
	t_stack	*stack_a;

	ft_count_elems(master);
	master->start_cmds = NULL;
	if (master->nb_a == 2)
		return (ft_swap_easy(master));
	if (master->nb_a == 3)
		return (1);
	med = (master->nb_a % 2 == 0) ? master->nb_a / 2 - 1 : master->nb_a / 2;
	count = 0;
	while (count <= med)
	{
		stack_a = master->a;
		if (stack_a->nb->pos <= med)
		{
			master->f[4](master, 1);
			count++;
		}
		else
			master->f[5](master, 1);
	}
	return (2);
}

void	ft_simple_tri(t_main *master)
{
	t_stack	*stack_a;

	stack_a = master->a;
	if (stack_a->nb->pos > stack_a->next->nb->pos &&
		stack_a->next->nb->pos > stack_a->next->next->nb->pos)
	{
		master->f[0](master, 1);
		master->f[8](master, 1);
	}
	else if (stack_a->nb->pos < stack_a->next->nb->pos &&
			stack_a->nb->pos < stack_a->next->next->nb->pos)
	{
		master->f[8](master, 1);
		master->f[0](master, 1);
	}
	else if (stack_a->nb->pos > stack_a->next->nb->pos &&
			stack_a->nb->pos < stack_a->next->next->nb->pos)
		master->f[0](master, 1);
	else if (stack_a->nb->pos < stack_a->next->nb->pos &&
			stack_a->nb->pos > stack_a->next->next->nb->pos)
		master->f[8](master, 1);
	else
		master->f[5](master, 1);
}

int		main(int ac, char **av)
{
	t_main	*master;
	int		i;

	if (ac == 1)
		return (0);
	if (!(master = (t_main*)malloc(sizeof(t_main))))
		return (0);
	if ((i = start_tab(ac, av, master)) <= 0)
		return (ft_print_swap_errors(i, master));
	if (ft_definitely_sorted(master))
	{
		free_swap(master);
		return (0);
	}
	if ((i = ft_first_sort(master)) == 2)
		ft_start_recursive(master);
	else if (i == 1)
		ft_simple_tri(master);
	ft_print_commands(master);
	free_checker(master, master->start_cmds);
	return (0);
}
