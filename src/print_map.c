/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:37 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:36:33 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	drw_ln(t_utils *mlx_ut, t_point start, t_point end)
{
	t_color		*first;
	int			line;
	t_bresenham	value;

	bresenham_init(mlx_ut, &value, start, end);
	first = mlx_ut->color_grad;
	line = choose_line_tp(mlx_ut, &value);
	if (line == 0 && value.dx > 0)
		ln_no_bre_x(mlx_ut, &value);
	else if (line == 0 && value.dy > 0)
		ln_no_bre_y(mlx_ut, &value);
	else if (line == -1 && value.dx >= value.dy)
		bresenham_x_dsc(mlx_ut, &value);
	else if (line == -1 && value.dy > value.dx)
		bresenham_y_dsc(mlx_ut, &value);
	else if (line == 1 && value.dx > value.dy)
		bresenham_x(mlx_ut, &value);
	else
		bresenham_y(mlx_ut, &value);
	mlx_ut->color_grad = first;
}

void	print_map(t_utils *m_u, t_point **pts)
{
	t_bresenham	point_value;
	int			x;
	int			y;

	y = 0;
	while (y < m_u->height)
	{
		x = 0;
		while (pts[y][x].is_end != 1)
		{
			if (pts[y][x].is_end != 1)
				drw_ln(m_u, pts[y][x], pts[y][x + 1]);
			if (y < m_u->height - 1)
				drw_ln(m_u, pts[y][x], pts[y + 1][x]);
			x++;
		}
		if (pts[y][x].is_end == 1 && y < m_u->height - 1)
			drw_ln(m_u, pts[y][x], pts[y + 1][x]);
		y++;
	}
}
