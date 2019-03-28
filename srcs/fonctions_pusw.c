/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:22:46 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/26 17:58:36 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap_a(t_main *master, int i)
{
	t_stack		*stack_a;
	t_number	*tmp;

	stack_a = master->a;
	if (!(stack_a) || !(stack_a->next))
		return ;
	tmp = stack_a->nb;
	stack_a->nb = stack_a->next->nb;
	stack_a->next->nb = tmp;
	if (i == 1)
		ft_add_cmds(master, (master->start_cmds), "sa");
	return ;
}

void	ft_swap_b(t_main *master, int i)
{
	t_stack		*stack_b;
	t_number	*tmp;

	stack_b = master->b;
	if (!(stack_b->nb) || !(stack_b->next))
		return ;
	tmp = stack_b->nb;
	stack_b->nb = stack_b->next->nb;
	stack_b->next->nb = tmp;
	if (i == 1)
		ft_add_cmds(master, (master->start_cmds), "sb");
	return ;
}

void	ft_swap_s(t_main *master, int i)
{
	ft_swap_a(master, 2);
	ft_swap_b(master, 2);
	if (i == 1)
		ft_add_cmds(master, (master->start_cmds), "ss");
	return ;
}

void	ft_push_a(t_main *master, int i)
{
	t_stack	*top_a;
	t_stack	*tmp;

	if (!(master->b->nb))
		return ;
	if (!(top_a = (t_stack*)malloc(sizeof(t_stack))))
		exit(1);
	master->a->prev = top_a;
	top_a->nb = master->b->nb;
	top_a->prev = NULL;
	top_a->next = master->a;
	master->a = top_a;
	tmp = master->b;
	if (master->b->next)
	{
		master->b = master->b->next;
		free(tmp);
		master->b->prev = NULL;
	}
	else
		master->b->nb = NULL;
	if (i == 1)
		ft_add_cmds(master, (master->start_cmds), "pa");
	return ;
}

void	ft_push_b(t_main *master, int i)
{
	t_stack	*top_b;

	if (!(master->a->nb) || !(top_b = (t_stack*)malloc(sizeof(t_stack))))
		return ;
	top_b->nb = master->a->nb;
	top_b->prev = NULL;
	if (master->b->nb)
	{
		top_b->next = master->b;
		master->b->prev = top_b;
	}
	else
	{
		free(master->b);
		top_b->next = NULL;
	}
	master->b = top_b;
	if (master->a->next)
		master->a = master->a->next;
	else
		master->a->nb = NULL;
	free(master->a->prev);
	master->a->prev = NULL;
	if (i == 1)
		ft_add_cmds(master, master->start_cmds, "pb");
}
