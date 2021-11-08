/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:59:39 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/08 09:54:56 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fdf.h"
#include <stdio.h>

void	drw_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2)
{
	int	dx;
	int dy;

	dx = x2 - x1;
	dy = y2 - y1;
	
	if ((dx < 0 || dy < 0) && (dx != 0 && dy != 0))
	{
		puts("PASSER");
		dsc_ln(mlx_ut, x1, y1, x2, y2);
	}
	else if (dx == 0 || dy == 0)
	{
		cst_ln(mlx_ut, x1, y1, x2, y2);
	}
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
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1++, y1,0xFFFF0000);
		}
		else
		{
			while (x1 >= x2)
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1--, y1,0xFFFF0000);			
		}
	}
	else
	{
		if (y1 <= y2)
		{
			while (y1 <= y2)
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1, y1++,0xFFFF0000);
		}
		else
		{
			while (y1 >= y2)
				mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1--, y1--,0xFFFF0000);			
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
	a = (double)dy / (double)dx;
	b = y1 - (a * x1);
	if (dy > dx)
	{
		x_y = x1;
		while (y1 <= y2)
		{
			mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, (int)x_y, y1,0xFFFF0000);
			x_y = ((y1 - b) / a) + 0.5;
			y1++;
		}
		while (y1 >= y2)
		{
			mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, (int)x_y, y1,0xFFFF0000);
			x_y = ((y1 - b) / a) + 0.5;
			y1--;
		}
	}
	else
	{
		x_y = y1;
		while (x1 <= x2)
		{
			mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1, (int)x_y,0xFFFF0000);
			x_y = ((a * x1) + b) + 0.5;
			x1++;
		}
		while (x1 >= x2)
		{
			mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1, (int)x_y,0xFFFF0000);
			x_y = ((a * x1) + b) + 0.5;
			x1--;
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
	a = (double)dy / (double)dx;
	b = y1 - (a * x1);
	if (dy > dx)
	{
		x_y = x1;
		while (y1 >= y2)
		{
			mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, (int)x_y, y1,0xFFFF0000);
			x_y = ((y1 - b) / a) + 0.5;
			y1--;
		}
		while (y1 <= y2)
		{
			mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, (int)x_y, y1,0xFFFF0000);
			x_y = ((y1 - b) / a) + 0.5;
			y1++;
		}
	}
	else
	{
		x_y = y1;
		while (x1 >= x2)
		{
			mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1, (int)x_y,0xFFFF0000);
			x_y = ((a * x1) + b) + 0.5;
			x1--;
		}
		while (x1 <= x2)
		{
			mlx_pixel_put(mlx_ut->mlx, mlx_ut->window, x1, (int)x_y,0xFFFF0000);
			x_y = ((a * x1) + b) + 0.5;
			x1++;
		}
	}
}