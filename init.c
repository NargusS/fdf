/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:06:33 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/01 20:29:14 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_init(t_utils *mlx_ut, t_bresenham *values, t_point start, t_point end)
{
	zoom(values, start, end, mlx_ut->zoom);
	altitude(values, start, end, mlx_ut->coef_z);
	if (start.color == -1)
		values->color1 = WHITE;
	else
		values->color1 = start.color;
	if (end.color == -1)
		values->color2 = WHITE;
	else
		values->color2 = end.color;
	isometric_projection(mlx_ut, &values->x1, &values->y1, values->z1);
	isometric_projection(mlx_ut, &values->x2, &values->y2, values->z2);
	scale(values, start, end, mlx_ut);
	values->dx = abs_value(values->x2 - values->x1);
	values->dy = abs_value(values->y2 - values->y1);
	if (values->dy != 0 && values->dx != 0)
	{
		values->a = (double)values->dy / (double)values->dx;
		values->b = values->y1 - (values->a * values->x1);
	}
}

void	fdf_init(t_utils *mlx_utils)
{
	mlx_utils->mlx = mlx_init();
	mlx_utils->window = mlx_new_window(mlx_utils->mlx, WIDTH, HEIGHT, "FDF");
	mlx_utils->img.img = mlx_new_image(mlx_utils->mlx, WIDTH, HEIGHT);
	mlx_utils->img.adrr = mlx_get_data_addr(mlx_utils->img.img, \
	&(mlx_utils->img.bits_per_pixel), &(mlx_utils->img.line_length), \
	&(mlx_utils->img.endian));
	mlx_utils->zoom = 10;
	mlx_utils->angle_x = (60 * M_PI) / 180;
	mlx_utils->angle_y = (30 * M_PI) / 180;
	mlx_utils->coef_z = 1;
	get_scale(mlx_utils, mlx_utils->points, (get_width_line(mlx_utils->points[(mlx_utils->height / 2) - 1])/2)- 1, (mlx_utils->height / 2) - 1);
}
