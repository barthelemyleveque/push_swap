/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleveque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:43:35 by bleveque          #+#    #+#             */
/*   Updated: 2018/11/22 16:42:00 by bleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (!(s1) && !(s2))
		return (1);
	else if (!(s1) || !(s2))
		return (0);
	while (s1[i] == s2[i])
	{
		if (s1[i + 1] == '\0' && s2[i + 1] == '\0')
			return (1);
		i++;
	}
	return (0);
}