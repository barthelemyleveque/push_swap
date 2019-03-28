/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:13:47 by bleveque          #+#    #+#             */
/*   Updated: 2019/03/26 17:24:26 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_tab_cmds(t_cmds **tab_cmds, char *line)
{
	t_cmds	*tmp;
	t_cmds	*new;

	if (!(*tab_cmds))
	{
		if (!((*tab_cmds) = (t_cmds*)malloc(sizeof(t_cmds) * 1)))
			return (0);
		if (!((*tab_cmds)->cmd = ft_strdup(line)))
			return (0);
		free(line);
		(*tab_cmds)->next = NULL;
		return (1);
	}
	tmp = (*tab_cmds);
	while (tmp->next)
		tmp = tmp->next;
	if (!(new = (t_cmds*)malloc(sizeof(t_cmds) * 1)))
		return (0);
	if (!(new->cmd = ft_strdup(line)))
		return (0);
	free(line);
	new->next = NULL;
	tmp->next = new;
	return (1);
}

int		function_calling(char *cmd)
{
	if (!(ft_strcmp(cmd, "sa")))
		return (0);
	else if (!(ft_strcmp(cmd, "sb")))
		return (1);
	else if (!(ft_strcmp(cmd, "ss")))
		return (2);
	else if (!(ft_strcmp(cmd, "pa")))
		return (3);
	else if (!(ft_strcmp(cmd, "pb")))
		return (4);
	else if (!(ft_strcmp(cmd, "ra")))
		return (5);
	else if (!(ft_strcmp(cmd, "rb")))
		return (6);
	else if (!(ft_strcmp(cmd, "rr")))
		return (7);
	else if (!(ft_strcmp(cmd, "rra")))
		return (8);
	else if (!(ft_strcmp(cmd, "rrb")))
		return (9);
	else if (!(ft_strcmp(cmd, "rrr")))
		return (10);
	return (-1);
}

int		execute_cmds(t_cmds *tab_cmds, t_main *master, int v)
{
	int	i;

	while (tab_cmds)
	{
		if (v == 1)
		{
			system("clear");
			ft_visualiser(master);
		}
		i = function_calling(tab_cmds->cmd);
		if (i == -1)
			return (0);
		master->f[i](master, 0);
		tab_cmds = tab_cmds->next;
	}
	if (v == 1)
	{
		system("clear");
		ft_visualiser(master);
	}
	if (!(ft_definitely_sorted(master)))
		return (-1);
	return (1);
}

int		main(int ac, char **av)
{
	t_main	*master;
	char	*cmd;
	t_cmds	*tab_cmds;
	int		i;
	int		v;

	if (ac == 1)
		return (0);
	v = 0;
	tab_cmds = NULL;
	if (!(ft_strcmp(av[1], "-v")))
		v = 1;
	if (!(master = (t_main*)malloc(sizeof(t_main))))
		return (0);
	if ((i = start_tab(ac, av, master)) <= 0)
		return (ft_print_swap_errors(i, master));
	while ((i = get_next_line(0, &cmd)))
		if (i == -1 || !(ft_tab_cmds(&tab_cmds, cmd)))
			return (ft_print_checker_errors(0, master, tab_cmds));
	if ((i = execute_cmds(tab_cmds, master, v)) <= 0)
		return (ft_print_checker_errors(i, master, tab_cmds));
	free_checker(master, tab_cmds);
	ft_printf("OK\n");
	return (0);
}
