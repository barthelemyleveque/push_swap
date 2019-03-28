/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   side.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 14:35:09 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/25 17:09:02 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rev_rotate_r(t_main *master, int i)
{
	ft_rev_rotate_a(master, 2);
	ft_rev_rotate_b(master, 2);
	if (i == 1)
		ft_add_cmds(master, (master->start_cmds), "rrr");
	return ;
}

void	*ft_free_long_tab(int *tab_i)
{
	free(tab_i);
	return (NULL);
}
