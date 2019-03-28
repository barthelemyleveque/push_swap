/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 14:47:50 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/25 17:45:36 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_count_elems(t_main *master)
{
	int		count;
	int		inter_max;
	t_stack	*a;
	t_stack	*b;

	a = master->a;
	b = master->b;
	count = 0;
	inter_max = master->a->nb->inter;
	while (a)
	{
		if (a->nb->inter == inter_max)
			count++;
		a = a->next;
	}
	master->nb_a = count;
	count = 0;
	while (b)
	{
		if (b->nb)
			count++;
		b = b->next;
	}
	master->nb_b = count;
}

void	ft_push_back(t_main *master)
{
	t_stack	*stack_a;

	stack_a = master->a;
	while (!(ft_definitely_sorted(master)) &&
			stack_a->nb->pos == (master->sorted_last + 1))
	{
		master->sorted_last = stack_a->nb->pos;
		stack_a->nb->inter = -1;
		master->f[5](master, 1);
		stack_a = master->a;
	}
	return ;
}

int		ft_add_cmds(t_main *master, t_cmds *tab_cmds, char *line)
{
	t_cmds	*tmp;
	t_cmds	*new;

	if (!(tab_cmds))
	{
		if (!((tab_cmds) = (t_cmds*)malloc(sizeof(t_cmds) * 1)))
			exit(1);
		if (!((tab_cmds)->cmd = ft_strdup(line)))
			exit(1);
		(tab_cmds)->next = NULL;
		master->start_cmds = (tab_cmds);
		return (1);
	}
	tmp = (tab_cmds);
	while (tmp->next)
		tmp = tmp->next;
	if (!(new = (t_cmds*)malloc(sizeof(t_cmds) * 1)))
		exit(1);
	if (!(new->cmd = ft_strdup(line)))
		exit(1);
	new->next = NULL;
	tmp->next = new;
	return (1);
}
