/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nuclear_reactor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:08:39 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/26 11:50:33 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	ft_start_recursive(t_main *master)
{
	if (ft_definitely_sorted(master))
		return ;
	ft_count_elems(master);
	if (master->sorted_last == -1)
	{
		ft_split_b(master, 0);
		ft_call_tri(master);
	}
	else if (master->nb_a <= 3 && master->nb_b == 0)
		ft_tri_a(master);
	else
	{
		ft_split_inter_a(master, master->a->nb->inter);
		if (ft_definitely_sorted(master))
			return ;
		if (master->b->nb)
		{
			ft_split_b(master, 0);
			ft_call_tri(master);
		}
	}
	ft_start_recursive(master);
	return ;
}

void	ft_split_inter_a(t_main *master, int inter)
{
	t_stack	*stack_a;

	while (master->a->nb->inter == inter)
	{
		stack_a = master->a;
		if (stack_a->nb->pos == master->sorted_last + 2 &&
			stack_a->next->nb->pos == master->sorted_last + 1)
			master->f[0](master, 1);
		if (master->a->nb->pos == master->sorted_last + 1)
		{
			ft_push_back(master);
			ft_count_elems(master);
		}
		else
			master->f[4](master, 1);
	}
}

/*
**  STACK 0 == A | STACK 1 == B
*/

int		ft_smallest_pos(t_main *master, int stack)
{
	t_stack	*pile;
	int		pos;

	pile = (stack == 0) ? master->a : master->b;
	pos = pile->nb->pos;
	while (pile)
	{
		if (pile->nb->pos < pos)
			pos = pile->nb->pos;
		pile = pile->next;
	}
	return (pos);
}

void	ft_split_b(t_main *master, int i)
{
	int		pos_med;
	int		inter;
	t_stack	*stack_b;

	ft_count_elems(master);
	if (master->nb_b <= 3)
		return ;
	pos_med = (master->nb_b / 2) + ft_smallest_pos(master, 1);
	pos_med += (master->nb_b % 2 == 1) ? 0 : -1;
	inter = master->a->nb->inter;
	while (i < master->nb_b / 2)
	{
		stack_b = master->b;
		if (stack_b->nb->pos > pos_med)
		{
			stack_b->nb->inter += inter + 1;
			master->f[3](master, 1);
			i++;
		}
		else
			master->f[6](master, 1);
	}
	ft_split_b(master, 0);
}
