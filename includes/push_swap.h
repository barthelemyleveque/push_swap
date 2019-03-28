/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:45:06 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/26 11:39:04 by bleveque         ###   ########.fr       */
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
}					t_number;

typedef struct		s_stack
{
	struct s_number	*nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct		s_cmds
{
	char			*cmd;
	struct s_cmds	*next;
}					t_cmds;

typedef struct		s_main
{
	t_stack			*a;
	t_stack			*b;
	int				nb_a;
	int				nb_b;
	int				sorted_last;
	void			(*f[10])();
	t_cmds			*start_cmds;
}					t_main;

void				ft_rev_rotate_r(t_main *master, int i);
int					ft_add_cmds(t_main *master, t_cmds *tab_cmds, char *line);
int					ft_print_checker_errors(int error, t_main *master,
					t_cmds *tab_cmds);
void				ft_print_commands(t_main *master);
int					ft_definitely_sorted(t_main *master);
int					start_tab(int ac, char **av, t_main *master);
void				ft_quicksort(int *tab, int start, int end);
t_main				*init_master(int *tab_int, int count, t_main *master);
t_stack				*ft_init_a(int *tab, int count);
void				ft_position(int *tab, int count, t_main *master);
void				ft_swap_a(t_main *master, int i);
void				ft_swap_b(t_main *master, int i);
void				ft_swap_s(t_main *master, int i);
void				ft_push_a(t_main *master, int i);
void				ft_push_b(t_main *master, int i);
void				ft_rotate_a(t_main *master, int i);
void				ft_rotate_b(t_main *master, int i);
void				ft_rotate_r(t_main *master, int i);
void				ft_rev_rotate_a(t_main *master, int i);
void				ft_rev_rotate_b(t_main *master, int i);
void				ft_visualiser(t_main *maser);
void				free_stack_a(t_main *master);
void				free_stack_b(t_main *master);
void				free_checker(t_main *master, t_cmds *tab_cmds);
int					ft_print_swap_errors(int error, t_main *master);
void				free_swap(t_main *master);
void				ft_count_elems(t_main *master);
void				ft_start_recursive(t_main *master);
int					ft_smallest_pos(t_main *master, int stack);
void				ft_split_b(t_main *master, int i);
void				ft_push_back(t_main *master);
void				ft_call_tri(t_main *master);
void				ft_push_back(t_main *master);
int					ft_count_inter(t_main *master);
void				ft_tri_b(t_main *master);
void				ft_tri_b_bis(t_main *master);
void				ft_tri_a(t_main *master);
void				ft_tri_a_hard(t_main *master);
void				ft_split_inter_a(t_main *master, int inter);
int					elems_inter(t_main *master, int inter);
int					ft_med_inter(t_main *master, int inter, int nb_elems);
int					ft_error_tab(int err, char ***tab);
int					*ft_duplicates(int *tab_i, int count);
int					ft_error_tab_int(int err, char ***tab, int *tab_int);
void				ft_rev_rotate_a(t_main *master, int i);
void				ft_rev_rotate_b(t_main *master, int i);
void				*ft_free_long_tab(int *tab_i);

#endif
