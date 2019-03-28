/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonctions_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 18:38:04 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/25 17:43:43 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate_a(t_main *master, int i)
{
	t_number	*tmp;
	t_stack		*last;

	last = master->a;
	if (!(last) || !(last->next))
		return ;
	while (last->next)
	{
		tmp = last->nb;
		last->nb = last->next->nb;
		last->next->nb = tmp;
		last = last->next;
	}
	if (i == 1)
		ft_add_cmds(master, (master->start_cmds), "ra");
	return ;
}

void	ft_rotate_b(t_main *master, int i)
{
	t_number	*tmp;
	t_stack		*last;
	t_number	*first;

	last = master->b;
	if (!(last) || !(last->next))
		return ;
	first = last->nb;
	while (last->next)
	{
		tmp = last->nb;
		last->nb = last->next->nb;
		last->next->nb = tmp;
		last = last->next;
	}
	if (i == 1)
		ft_add_cmds(master, (master->start_cmds), "rb");
	return ;
}

void	ft_rotate_r(t_main *master, int i)
{
	ft_rotate_a(master, 2);
	ft_rotate_b(master, 2);
	if (i == 1)
		ft_add_cmds(master, (master->start_cmds), "rr");
	return ;
}

void	ft_rev_rotate_a(t_main *master, int i)
{
	t_number	*rev;
	t_stack		*last;

	last = master->a;
	if (!(last) || !(last->next))
		return ;
	while (last->next)
		last = last->next;
	while (last->prev)
	{
		rev = last->nb;
		last->nb = last->prev->nb;
		last->prev->nb = rev;
		last = last->prev;
	}
	if (i == 1)
		ft_add_cmds(master, (master->start_cmds), "rra");
	return ;
}

void	ft_rev_rotate_b(t_main *master, int i)
{
	t_number	*rev;
	t_stack		*last;

	last = master->b;
	if (!(last) || !(last->next))
		return ;
	while (last->next)
		last = last->next;
	while (last->prev)
	{
		rev = last->nb;
		last->nb = last->prev->nb;
		last->prev->nb = rev;
		last = last->prev;
	}
	if (i == 1)
		ft_add_cmds(master, (master->start_cmds), "rrb");
	return ;
}
