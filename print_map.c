/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:37 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/01 16:30:27 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drw_ln(t_utils *mlx_ut, t_bresenham *value)
{
	if (value->dx == 0 || value->dy == 0)
	{
		ln_no_bre(mlx_ut, value);
		return;
	}
	else if ((value->y1 > value->y2 && value->x1 < value->x2)
		|| (value->y1 < value->y2 && value->x1 > value->x2))
	{
		if (value->x1 >= value->x2)
			value->sens = 1.0;
		else
			value->sens = -0.5;
		if (value->dx > value->dy)
			bresenham_x_dsc(mlx_ut, value);
		else
			bresenham_y_dsc(mlx_ut, value);
		return;
	}
	else
	{
		value->sens = 0.5;
		if (value->dx > value->dy)
			bresenham_x(mlx_ut, value);
		else
			bresenham_y(mlx_ut, value);
		return;
	}
}

void	print_map(t_utils *m_u, t_point **pts)
{
	t_bresenham	point_value;
	int x;
	int	y;

	y = 0;
	while (y < m_u->height)
	{
		x = 0;
		while (pts[y][x].is_end != 1)
		{
			if (pts[y][x].is_end != 1)
			{
				bresenham_init(m_u, &point_value, pts[y][x], pts[y][x+1]);
				drw_ln(m_u, &point_value);
			}
			if (y < m_u->height - 1)
			{
				bresenham_init(m_u, &point_value, pts[y][x], pts[y + 1][x]);
				drw_ln(m_u, &point_value);
			}
			x++;
		}
		if (pts[y][x].is_end == 1 && y < m_u->height - 1)
		{
			bresenham_init(m_u, &point_value, pts[y][x], pts[y + 1][x]);
			drw_ln(m_u, &point_value);
		}
		y++;
	}
}
