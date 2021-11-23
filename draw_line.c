/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:59:39 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/23 20:35:54 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fdf.h"
#define BLUE 0xFF07ACFF
#include <stdio.h>

void	drw_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2, t_point **pts)
{
	int	dx;
	int dy;
	int z;
	int z1;

	z = pts[y1][x1].z;
	z1 = pts[y2][x2].z;

	x1 *= mlx_ut->zoom;
	y1 *= mlx_ut->zoom;
	x2 *= mlx_ut->zoom;
	y2 *= mlx_ut->zoom;
	isometric_projection(mlx_ut->angle, &x1, &y1, z * mlx_ut->coef_z);
	isometric_projection(mlx_ut->angle, &x2, &y2, z1 * mlx_ut->coef_z);
	x1 += mlx_ut->scale_x;
	y1 += mlx_ut->scale_y;
	x2 += mlx_ut->scale_x;
	y2 += mlx_ut->scale_y;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	if (((y1 > y2 && x1 < x2) || (y1 < y2 && x1 > x2)) && (dx != 0 && dy != 0))
		dsc_ln(mlx_ut, x1, y1, x2, y2);
	else if (dx == 0 || dy == 0)
		cst_ln(mlx_ut, x1, y1, x2, y2);
	else
		asc_ln(mlx_ut, x1, y1, x2, y2);
}

void	cst_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2)
{
	int	dx;
	int dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx > 0)
	{
		if (x1 <= x2)
		{
			while (x1 <= x2)
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1++, y1,BLUE);
		}
		else
		{
			while (x1 >= x2)
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1--, y1,BLUE);			
		}
	}
	else
	{
		if (y1 <= y2)
		{
			while (y1 <= y2)
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1, y1++,BLUE);
		}
		else
		{
			while (y1 >= y2)
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1--, y1--,BLUE);			
		}
	}
}

void	asc_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2)
{
	int 	dx;
	int 	dy;
	double	b;
	double	a;
	double	x_y;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	a = (double)dy / (double)dx;
	b = y1 - (a * x1);
	if (dy > dx)
	{
		x_y = x1;
		if (y1 <= y2)
		{
			while (y1 <= y2)
			{
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, (int)x_y, y1,BLUE);
				x_y = ((y1 - b) / a) + 0.5;
				y1++;
			}
		}
		else
		{
			while (y1 >= y2)
			{
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, (int)x_y, y1,BLUE);
				x_y = ((y1 - b) / a) + 0.5;
				y1--;
			}
		}
	}
	else
	{
		x_y = y1;
		if (x1 <= x2)
		{
			while (x1 <= x2)
			{
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1, (int)x_y,BLUE);
				x_y = ((a * x1) + b) + 0.5;
				x1++;
			}
		}
		else
		{
			while (x1 >= x2)
			{
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1, (int)x_y,BLUE);
				x_y = ((a * x1) + b) + 0.5;
				x1--;
			}
		}
	}
}

void	dsc_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2)
{
	int 	dx;
	int 	dy;
	double	b;
	double	a;
	double	x_y;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;
	a = (double)dy / (double)dx;
	b = y1 - (a * x1);

	if (dy > dx)
	{

		x_y = x1;
		if (y1 >= y2)
		{
			while (y1 >= y2)
			{
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, (int)x_y, y1,BLUE);
				x_y = x1 + (x1 - ((y1 - b) / a) + 1.0);
				y1--;
			}
		}
		else 
		{
			while (y1 <= y2)
			{
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, (int)x_y, y1,BLUE);
				x_y = x1 + (x1 - ((y1 - b) / a) - 0.5);
				y1++;
			}
		}
	}
	else
	{
		x_y = y1;
		if (x1 >= x2)
		{
			while (x1 >= x2)
			{
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1, (int)x_y,BLUE);
				x_y = y1 + (y1 - ((a * x1) + b) + 1.0);
				x1--;
			}
		}
		else
		{
			while (x1 <= x2)
			{
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1, (int)x_y,BLUE);
				x_y = y1 + (y1 - ((a * x1) + b) - 0.5);
				x1++;
			}
		}
	}
}