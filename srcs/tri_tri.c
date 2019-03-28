/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_tri.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 12:39:58 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/25 17:48:43 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_duo_duo(t_main *master)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = master->a;
	stack_b = master->b;
	if (stack_b->nb->pos < stack_b->next->nb->pos)
	{
		if (stack_a->nb->pos > stack_a->next->nb->pos)
			master->f[2](master, 1);
		else
			master->f[1](master, 1);
	}
	else if (stack_a->next && stack_a->nb->pos > stack_a->next->nb->pos)
		master->f[0](master, 1);
	master->f[3](master, 1);
	master->f[3](master, 1);
	ft_push_back(master);
	return ;
}

void	ft_duo_tri(t_main *master)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = master->a;
	stack_b = master->b;
	if (stack_a->nb->pos > stack_a->next->nb->pos)
		master->f[0](master, 1);
	ft_tri_b(master);
	master->f[3](master, 1);
	master->f[3](master, 1);
	master->f[3](master, 1);
	ft_push_back(master);
	return ;
}

void	ft_tri_tri(t_main *master)
{
	int	inter_a;

	inter_a = master->a->nb->inter;
	ft_tri_b(master);
	master->f[3](master, 1);
	master->f[3](master, 1);
	master->f[3](master, 1);
	ft_push_back(master);
	if (master->a->nb->inter == inter_a)
	{
		ft_tri_a(master);
		ft_push_back(master);
	}
	return ;
}

void	ft_call_tri(t_main *master)
{
	ft_count_elems(master);
	if (master->nb_b == 1)
	{
		master->f[3](master, 1);
		ft_push_back(master);
	}
	else if (master->nb_b == 2)
		ft_duo_duo(master);
	else if (master->nb_b == 3 && ft_count_inter(master) == 2)
		ft_duo_tri(master);
	else
		ft_tri_tri(master);
	return ;
}
