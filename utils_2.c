/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:17:50 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/22 10:20:39 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
