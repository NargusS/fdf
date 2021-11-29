/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:59:39 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/29 01:51:11 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fdf.h"
#define BLUE 0xFF07ACFF
#define	WHITE 16777215
#include <stdio.h>

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*p_adrr;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		p_adrr = data->adrr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)p_adrr = (unsigned int)color;
	}
}

void	ln_no_bre(t_utils *mlx_ut, t_bresenham *value)
{
	if (value->dx == 0)
	{
		while (value->y1 <= value->y2)
			my_mlx_pixel_put(&mlx_ut->img, value->x1, (value->y1)++,16777215);
	}
	else
	{
		while (value->x1 <= value->x2)
			my_mlx_pixel_put(&mlx_ut->img, (value->x1)++, value->y1,16777215);
	}
}

void	drw_ln(t_utils *mlx_ut, t_bresenham *value)
{
	if (value->dx == 0 || value->dy == 0)
		ln_no_bre(mlx_ut, value);
	else if (value->dy > value->dx)
	{
		if (value->y2 > value->y1 && value->x1 < value->x2)
		{
			value->sens = 1.0;
			bresenham_y_dsc(mlx_ut, value);
		}
		else if (value->y2 < value->y1 && value->x1 > value->x2)
		{
			value->sens = -0.5;
			bresenham_y_dsc(mlx_ut, value);
		}
		else
		{
			value->sens = 0.5;
			bresenham_y(mlx_ut, value);
		}
	}
	else
	{
		if (value->x1 > value->x2 && value->y1 < value->y2)
		{
			value->sens = 1.0;
			bresenham_x_dsc(mlx_ut, value);
		}
		else if (value->x1 < value->x2 && value->y1 > value->y2)
		{
			value->sens = -0.5;
			bresenham_x_dsc(mlx_ut, value);
		}
		else
		{
			value->sens = 0.5;
			bresenham_x(mlx_ut, value);
		}
	}
}

int	abs_value(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

void	bresenham_x(t_utils *mlx_ut, t_bresenham *value)
{
	double y;

	y = (double)value->y1;
	while ((value->x1 <= value->x2) || (value->x1 >= value->x2))
	{
		my_mlx_pixel_put(&mlx_ut->img, value->x1, (int)y, WHITE);
		y = ((value->a * value->x1) + value->b) + 0.5;
		if (value->x1 < value->x2)
			value->x1++;
		else if (value->x1 > value->x2)
			value->x1--;
		else
		{
			my_mlx_pixel_put(&mlx_ut->img, value->x1, (int)y, WHITE);
			break;
		}	
	}
}

void	bresenham_x_dsc(t_utils *mlx_ut, t_bresenham *value)
{
	double y;

	y = (double)value->y1;
	while ((value->x1 <= value->x2) || (value->x1 >= value->x2))
	{
		my_mlx_pixel_put(&mlx_ut->img, value->x1, (int)y, WHITE);
		y = value->y1 + (value->y1 - ((value->a * value->x1) + value->b) + value->sens);
		if (value->x1 < value->x2)
			value->x1++;
		else if (value->x1 > value->x2)
			value->x1--;
		else
		{
			my_mlx_pixel_put(&mlx_ut->img, value->x1, (int)y,WHITE);
			break;
		}	
	}
}

void	bresenham_y(t_utils *mlx_ut, t_bresenham *value)
{
	double x;

	x = (double)value->x1;
	while ((value->y1 <= value->x2) || (value->y1) >= value->y2)
	{
		my_mlx_pixel_put(&mlx_ut->img, (int)x, value->y1,WHITE);
		x = ((value->y1 - value->b) / value->a) + 0.5;
		if (value->y1 < value->y2)
			value->y1++;
		else if (value->y1 > value->y2)
			value->y1--;
		else
		{
			my_mlx_pixel_put(&mlx_ut->img, (int)x, value->y1,WHITE);
			break;
		}
	}
}

void	bresenham_y_dsc(t_utils *mlx_ut, t_bresenham *value)
{
	double x;

	x = (double)value->x1;
	while ((value->y1 <= value->x2) || (value->y1) >= value->y2)
	{
		my_mlx_pixel_put(&mlx_ut->img, (int)x, value->y1,WHITE);
		x = value->x1 + (value->x1 - ((value->y1 - value->b) / value->a) + value->sens);
		if (value->y1 < value->y2)
			value->y1++;
		else if (value->y1 > value->y2)
			value->y1--;
		else
		{
			my_mlx_pixel_put(&mlx_ut->img, (int)x, value->y1,WHITE);
			break;
		}
	}
}