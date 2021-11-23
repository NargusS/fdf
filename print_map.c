/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:37 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/23 20:34:50 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(double angle, int *x, int *y, int z)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

int		get_width_line(t_point *pts)
{
	int	width;

	width = 0;
	while (pts[width].is_end != 1)
		width++;
	return (width + 1);
}

void	scale_center(t_utils *mlx, t_point **pts, int x, int y)
{
	int	x_diff;
	int y_diff;

	x_diff = pts[y][x].x * mlx->zoom;
	y_diff = pts[y][x].y * mlx->zoom;
	isometric_projection(mlx->angle, &x_diff, &y_diff, pts[y][x].z * mlx->coef_z);
	if (x_diff <= 500)
		x_diff = 500 - x_diff;
	else
	{
		x_diff = x_diff - 500;
		x_diff = -x_diff;
	}
	if (y_diff <= 500)
		y_diff = 500 - y_diff;
	else
	{
		y_diff = y_diff - 500;
		y_diff = -y_diff;
	}
	mlx->scale_x = x_diff;
	mlx->scale_y = y_diff;
}

void	print_map(t_utils *m_u, t_point **pts)
{
	int x;
	int	y;

	y = 0;
	scale_center(m_u, pts, (get_width_line(pts[(m_u->height / 2) - 1])/2)- 1, (m_u->height / 2) - 1);
	while (y < m_u->height)
	{
		x = 0;
		while (pts[y][x].is_end != 1)
		{
			if (pts[y][x].is_end != 1)
				drw_ln(m_u, pts[y][x].x, pts[y][x].y, pts[y][x + 1].x, pts[y][x + 1].y, pts);
			if (y < m_u->height - 1)
				drw_ln(m_u, pts[y][x].x, pts[y][x].y, pts[y + 1][x].x, pts[y + 1][x].y, pts);
			x++;
		}
		if (pts[y][x].is_end == 1 && y < m_u->height - 1)
			drw_ln(m_u, pts[y][x].x, pts[y][x].y, pts[y + 1][x].x, pts[y + 1][x].y, pts);
		y++;
	}
	// cst_ln(m_u, 500, 0, 500, 1000);
	// cst_ln(m_u, 0, 500, 1000, 500);
}