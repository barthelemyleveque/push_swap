/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:45:06 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/15 16:13:50 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../libft/header.h"
# include "../libft/get_next_line.h"
# include <limits.h>

typedef struct		s_number
{
	int				val;
	int				pos;
	int				inter;
}

typedef struct		s_stack
{
	struct s_number	nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_main
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				nb_elems_a;
	int				nb_elems_b;
	int				sorted_last;
}					t_main;

void	ft_quicksort(int *tab, int start, int end);

#endif
