/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 16:28:44 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/25 18:11:04 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_check(t_stack *start)
{
	t_stack	*tmp;

	tmp = start;
	while (tmp)
	{
		if (tmp->next && !(tmp->next->nb))
		{
			free(tmp->next);
			tmp->next = NULL;
		}
		tmp = tmp->next;
	}
	return ;
}

t_stack	*ft_init_a(int *tab, int count)
{
	int		i;
	t_stack	*stack_a;
	t_stack *start;
	t_stack *tmp;

	if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stack_a->prev = NULL;
	start = stack_a;
	i = -1;
	while (++i <= count)
	{
		if (!(stack_a->nb = (t_number*)malloc(sizeof(t_number))))
			return (NULL);
		stack_a->nb->val = tab[i];
		stack_a->nb->inter = 0;
		if (!(stack_a->next = (t_stack*)malloc(sizeof(t_stack))))
			return (NULL);
		stack_a->next->nb = NULL;
		tmp = stack_a;
		stack_a = stack_a->next;
		stack_a->prev = tmp;
	}
	ft_check(start);
	return (start);
}

void	init_fonctions(void (*f[10])())
{
	f[0] = ft_swap_a;
	f[1] = ft_swap_b;
	f[2] = ft_swap_s;
	f[3] = ft_push_a;
	f[4] = ft_push_b;
	f[5] = ft_rotate_a;
	f[6] = ft_rotate_b;
	f[7] = ft_rotate_r;
	f[8] = ft_rev_rotate_a;
	f[9] = ft_rev_rotate_b;
	f[10] = ft_rev_rotate_r;
}

t_main	*init_master(int *tab_int, int count, t_main *master)
{
	t_stack	*a;
	t_stack	*b;

	if (!(a = ft_init_a(tab_int, count)))
		return (NULL);
	if (!(b = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	b->next = NULL;
	b->prev = NULL;
	b->nb = NULL;
	master->a = a;
	master->b = b;
	master->nb_a = count;
	master->nb_b = 0;
	master->sorted_last = -1;
	ft_position(tab_int, count, master);
	init_fonctions(master->f);
	return (master);
}

void	ft_position(int *tab, int count, t_main *master)
{
	int		i;
	t_stack	*start;

	i = 0;
	ft_quicksort(tab, 0, count);
	start = master->a;
	while (i <= count)
	{
		master->a = start;
		while (master->a)
		{
			if ((master->a->nb->val == tab[i]) ||
					(tab[i] == 0 && master->a->nb->val == 0))
			{
				master->a->nb->pos = i;
				break ;
			}
			else
				master->a = master->a->next;
		}
		i++;
	}
	master->a = start;
}
