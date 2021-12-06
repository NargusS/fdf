/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:52:27 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:22:54 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_tab_str(char ***tab_str, int i)
{
	if (i < 0)
	{
		i = 0;
		while ((*tab_str)[i])
		{
			if ((*tab_str)[i])
				free((*tab_str)[i++]);
			else
				i++;
		}
	}
	else
	{
		while (i >= 0)
		{
			if ((*tab_str)[i])
				free((*tab_str)[i--]);
			else
				i--;
		}
	}
	if (*tab_str)
		free((*tab_str));
}

void	free_points(t_point ***points, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if ((*points)[i])
			free((*points)[i++]);
		else
			i++;
	}
	if ((*points))
		free((*points));
}
