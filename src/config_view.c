/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:05:21 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:22:08 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	isometric_projection(t_utils *mlx_ut, int *x, int *y, int z)
{
	*x = (*x - *y) * cos(mlx_ut->angle_x);
	*y = -z + (*x + *y) * sin(mlx_ut->angle_y);
}

void	zoom(t_bresenham *values, t_point start, t_point end, int zoom)
{
	values->x1 = start.x * zoom;
	values->y1 = start.y * zoom;
	values->x2 = end.x * zoom;
	values->y2 = end.y * zoom;
}

void	altitude(t_bresenham *values, t_point start, t_point end, int altitude)
{
	values->z1 = start.z * altitude;
	values->z2 = end.z * altitude;
}

void	get_scale(t_utils *mlx, t_point **pts, int x, int y)
{
	int	x_diff;
	int	y_diff;

	x_diff = pts[y][x].x * mlx->zoom;
	y_diff = pts[y][x].y * mlx->zoom;
	isometric_projection(mlx, &x_diff, &y_diff, pts[y][x].z * mlx->coef_z);
	if (x_diff <= WIDTH / 2)
		x_diff = (WIDTH / 2) - x_diff;
	else
	{
		x_diff = x_diff - (WIDTH / 2);
		x_diff = -x_diff;
	}
	if (y_diff <= (HEIGHT / 2))
		y_diff = (HEIGHT / 2) - y_diff;
	else
	{
		y_diff = y_diff - (HEIGHT / 2);
		y_diff = -y_diff;
	}
	mlx->scale_x = x_diff;
	mlx->scale_y = y_diff;
}

void	scale(t_bresenham *values, t_point start, t_point end, t_utils *mlx_ut)
{
	values->x1 += mlx_ut->scale_x;
	values->y1 += mlx_ut->scale_y;
	values->x2 += mlx_ut->scale_x;
	values->y2 += mlx_ut->scale_y;
}
