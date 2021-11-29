/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:37 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/29 02:28:13 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(t_utils *mlx_ut, int *x, int *y, int z)
{
	*x = (*x - *y) * cos(mlx_ut->angle_x);
	*y = -z + (*x + *y) * sin(mlx_ut->angle_y);
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
	isometric_projection(mlx, &x_diff, &y_diff, pts[y][x].z + mlx->coef_z);
	if (x_diff <= WIDTH/2)
		x_diff = (WIDTH/2) - x_diff;
	else
	{
		x_diff = x_diff - (WIDTH/2);
		x_diff = -x_diff;
	}
	if (y_diff <= (HEIGHT/2))
		y_diff = (HEIGHT/2) - y_diff;
	else
	{
		y_diff = y_diff - (HEIGHT/2);
		y_diff = -y_diff;
	}
	mlx->scale_x = x_diff;
	mlx->scale_y = y_diff;
}

void	print_map(t_utils *m_u, t_point **pts)
{
	t_bresenham	point_value;
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

void	bresenham_init(t_utils *mlx_ut, t_bresenham *values, t_point start, t_point end)
{
	values->x1 = start.x * mlx_ut->zoom;
	values->y1 = start.y * mlx_ut->zoom;
	values->z1 = start.z;
	values->color1 = start.color;
	values->x2 = end.x * mlx_ut->zoom;
	values->y2 = end.y * mlx_ut->zoom;
	values->z2 = end.z;
	values->color2 = end.color;
	isometric_projection(mlx_ut, &values->x1, &values->y1, values->z1);
	isometric_projection(mlx_ut, &values->x2, &values->y2,values->z2);
	values->dx = abs_value(values->x2 - values->x1);
	values->dy = abs_value(values->y2 - values->y1);
	values->x1 += mlx_ut->scale_x;
	values->y1 += mlx_ut->scale_y;
	values->x2 += mlx_ut->scale_x;
	values->y2 += mlx_ut->scale_y;
	printf("%d %d\n", values->z1, values->z2);
	if (values->dy != 0 && values->dx != 0)
	{
		values->a = (double)values->dy / (double)values->dx;
		values->b = values->y1 - (values->a * values->x1);
	}
}