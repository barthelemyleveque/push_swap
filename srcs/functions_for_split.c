/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_for_split.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:54:41 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/25 17:43:55 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		elems_inter(t_main *master, int inter)
{
	t_stack	*stack_a;
	int		i;

	stack_a = master->a;
	i = 0;
	while (stack_a->nb->inter == inter)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

int		ft_smallest_pos_inter(t_main *master, int inter)
{
	t_stack	*stack_a;
	int		pos;

	stack_a = master->a;
	pos = stack_a->nb->pos;
	while (stack_a->nb->inter == inter)
	{
		if (stack_a->nb->pos < pos)
			pos = stack_a->nb->pos;
		stack_a = stack_a->next;
	}
	return (pos);
}

int		ft_med_inter(t_main *master, int inter, int nb_elems)
{
	int		med;

	if (nb_elems % 2 == 0)
		med = nb_elems / 2 - 1 + ft_smallest_pos_inter(master, inter);
	else
		med = nb_elems / 2 + ft_smallest_pos_inter(master, inter);
	return (med);
}
