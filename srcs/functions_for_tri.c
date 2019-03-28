/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_tri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:15:02 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/25 18:00:57 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_count_inter(t_main *master)
{
	t_stack	*stack_a;
	int		i;
	int		inter_max;

	i = 0;
	stack_a = master->a;
	inter_max = stack_a->nb->inter;
	while (stack_a && stack_a->nb->inter == inter_max)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

/*
** Grace au push_back dans tri_tri, on a seulement 4 poss a gerer :
** Cas 1 : 4 3 5
** Cas 2 : 4 5 3
** Cas 3 : 5 3 4
** Cas 4 : 5 4 3
*/

void	ft_tri_a_hard(t_main *master)
{
	t_stack	*stack_a;

	stack_a = master->a;
	if (stack_a->nb->pos < stack_a->next->next->nb->pos)
		master->f[0](master, 1);
	else if (stack_a->nb->pos < stack_a->next->nb->pos)
	{
		master->f[4](master, 1);
		master->f[0](master, 1);
		ft_push_back(master);
		master->f[3](master, 1);
	}
	else if (stack_a->nb->pos > stack_a->next->next->nb->pos)
		master->f[0](master, 1);
	else
	{
		master->f[4](master, 1);
		master->f[0](master, 1);
		ft_push_back(master);
		master->f[3](master, 1);
	}
	return ;
}

void	ft_tri_a(t_main *master)
{
	t_stack	*stack_a;

	ft_count_elems(master);
	stack_a = master->a;
	if (master->nb_a == 2)
	{
		if (stack_a->nb->pos > stack_a->next->nb->pos)
			master->f[0](master, 1);
	}
	else if (master->nb_a == 3)
		ft_tri_a_hard(master);
	ft_push_back(master);
	return ;
}

/*
** STACK A == 0 STACK B == 1
** cas 1 : 2 / 1 / 0
** cas 2 : 1 / 0 / 2
** cas 3 : 1 / 2 / 0
** cas 4 : 0 / 2 / 1
** cas 5 : 2 / 0 / 1 : push b
** ----
** cas 6 : 0 / 1 / 2 : push b
*/

void	ft_tri_b(t_main *master)
{
	int		sp;
	t_stack	*stack_b;

	stack_b = master->b;
	sp = ft_smallest_pos(master, 1);
	if (stack_b->nb->pos > stack_b->next->nb->pos &&
		stack_b->next->nb->pos > stack_b->next->next->nb->pos)
		return ;
	else if (stack_b->nb->pos > stack_b->next->nb->pos &&
			stack_b->nb->pos < stack_b->next->next->nb->pos)
		master->f[9](master, 1);
	else if (stack_b->nb->pos < stack_b->next->nb->pos &&
			stack_b->nb->pos != sp && stack_b->next->nb->pos != sp)
		master->f[1](master, 1);
	else if (stack_b->nb->pos == sp &&
			stack_b->next->nb->pos > stack_b->next->next->nb->pos)
		master->f[6](master, 1);
	else if (stack_b->nb->pos > stack_b->next->nb->pos &&
			stack_b->nb->pos > stack_b->next->next->nb->pos)
	{
		master->f[3](master, 1);
		master->f[1](master, 1);
	}
	else
		ft_tri_b_bis(master);
}

void	ft_tri_b_bis(t_main *master)
{
	master->f[6](master, 1);
	master->f[1](master, 1);
}
