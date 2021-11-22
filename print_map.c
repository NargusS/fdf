/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:37 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/22 15:17:20 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_point **points, t_utils *mlx_utils)
{
	int y;
	int x;

	y = 0;
	while (y < mlx_utils->height)
	{
		x = 0;
		while (points[y][x].is_end != 1)
		{
			points[y][x].x = (points[y][x].x - points[y][x].y) * cos(0.8);
			points[y][x].y = (points[y][x].x + points[y][x].y) * (sin(0.8) - points[y][x].z);
			x++;
		}
		y++;
	}
}

void	print_map(t_utils *mlx_utils, t_point **points)
{
	int	x1;
	int	y1;
	int x;
	int	y;
	int	x_next;
	int	y_next;

	y = 0;
	x1 = 0;
	y1 = 0;
	x_next = 0;
	y_next = 0;
	while (y < mlx_utils->height - 1)
	{
		x = 0;
		x1 = 0;
		if (y1 == 0)
			y1 = points[y][x].y;
		while (points[y][x].is_end != 1)
		{
			if (x1 == 0)
				x1 = points[y][x].x;
			x_next = x1 + 0;
			y_next = y1 + 0;
			drw_ln(mlx_utils, x1, y1, x_next, y1);
			drw_ln(mlx_utils, x1, y1, x1, y_next);
			x1 = x_next;
			x++;
		}
		if (points[y][x].is_end == 1)
			drw_ln(mlx_utils, x1, y1, x1, y_next);
		y1 = y_next;
		y++;
	}
	if (y == mlx_utils->height - 1)
	{
		x = 0;
		x1 = 0;
		while (points[y][x].is_end != 1)
		{
			if (x1 == 0)
				x1 = points[y][x].x;
			x_next = x1 + 0;
			drw_ln(mlx_utils, x1, y1, x_next, y1);
			x1 = x_next;
			x++;
		}
	}
		
}