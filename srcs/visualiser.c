/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:35:40 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/25 18:51:04 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_time(int i)
{
	usleep(i);
	system("clear");
}

void	ft_visualiser(t_main *master)
{
	t_stack	*a;
	t_stack	*b;

	a = master->a;
	b = master->b;
	ft_printf("---  STACK A  ---    ---  STACK B --- \n");
	ft_printf(" val - pos - med |  | val - pos - med \n");
	while ((a) || (b))
	{
		if (a && a->nb)
			ft_printf(" %3d - %3d - %3d |  |", a->nb->val, a->nb->pos,
					a->nb->inter);
		else
			ft_printf("     -     -     |  |");
		if (b && b->nb)
			ft_printf(" %3d - %3d - %3d \n", b->nb->val, b->nb->pos,
					b->nb->inter);
		else
			ft_printf("     -     -    \n");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_time(150000);
}

void	ft_print_commands(t_main *master)
{
	t_cmds	*start;

	start = master->start_cmds;
	while (start)
	{
		ft_printf("%s\n", start->cmd);
		start = start->next;
	}
}
