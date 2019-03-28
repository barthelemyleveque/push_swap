/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_for_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:20:41 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/25 17:48:30 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack_a(t_main *master)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	stack_a = master->a;
	while (stack_a)
	{
		tmp = stack_a->next;
		free(stack_a->nb);
		free(stack_a);
		stack_a = tmp;
	}
}

int		ft_error_tab_int(int err, char ***tab, int *tab_int)
{
	int	i;

	i = ft_error_tab(err, tab);
	free(tab_int);
	return (i);
}

void	free_stack_b(t_main *master)
{
	t_stack	*stack_b;
	t_stack	*tmp;

	stack_b = master->b;
	while (stack_b)
	{
		tmp = stack_b;
		free(stack_b->nb);
		stack_b = stack_b->next;
		free(tmp);
	}
}

void	free_swap(t_main *master)
{
	free_stack_a(master);
	free_stack_b(master);
	free(master);
}

void	free_checker(t_main *master, t_cmds *tab_cmds)
{
	t_cmds	*tmp;

	tmp = tab_cmds;
	while (tab_cmds)
	{
		tmp = tab_cmds->next;
		free(tab_cmds->cmd);
		free(tab_cmds);
		tab_cmds = tmp;
	}
	free_stack_b(master);
	free_stack_a(master);
	free(master);
}
