/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:59:39 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/01 20:34:06 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ln_no_bre(t_utils *mlx_ut, t_bresenham *value)
{
	if (value->dx == 0)
	{
		while (value->y1 <= value->y2 || value->y1 >= value->y2)
		{
			my_mlx_pixel_put(&mlx_ut->img, value->x1, value->y1, value->color1);
			if (value->y1 < value->y2)
				value->y1++;
			else if (value->y1 > value->y2)
				value->y1--;
			else
			{
				my_mlx_pixel_put(&mlx_ut->img, value->x1, value->y1, value->color1);
				break ;
			}
		}
	}
	else
	{
		while (value->x1 <= value->x2 || value->x1 >= value->x2)
		{
			my_mlx_pixel_put(&mlx_ut->img, value->x1, value->y1, value->color1);
			if (value->x1 < value->x2)
				value->x1++;
			else if (value->x1 > value->x2)
				value->x1--;
			else
			{
				my_mlx_pixel_put(&mlx_ut->img, value->x1, value->y1, value->color1);
				break ;
			}
		}
	}
}

void	bresenham_x(t_utils *mlx_ut, t_bresenham *value)
{
	double	y;

	y = (double)value->y1;
	while ((value->x1 <= value->x2) || (value->x1 >= value->x2))
	{
		my_mlx_pixel_put(&mlx_ut->img, value->x1, (int)y, value->color1);
		y = ((value->a * value->x1) + value->b) + 0.5;
		if (value->x1 < value->x2)
			value->x1++;
		else if (value->x1 > value->x2)
			value->x1--;
		else
		{
			my_mlx_pixel_put(&mlx_ut->img, value->x1, (int)y, value->color1);
			break ;
		}	
	}
}

void	bresenham_x_dsc(t_utils *mlx_ut, t_bresenham *value)
{
	double	y;

	y = (double)value->y1;
	while ((value->x1 <= value->x2) || (value->x1 >= value->x2))
	{
		my_mlx_pixel_put(&mlx_ut->img, value->x1, (int)y, value->color1);
		y = value->y1 + (value->y1 - ((value->a * value->x1) + value->b) + value->sens);
		if (value->x1 < value->x2)
			value->x1++;
		else if (value->x1 > value->x2)
			value->x1--;
		else
		{
			my_mlx_pixel_put(&mlx_ut->img, value->x1, (int)y, value->color1);
			break ;
		}	
	}
}

void	bresenham_y(t_utils *mlx_ut, t_bresenham *value)
{
	double	x;

	x = (double)value->x1;
	while ((value->y1 <= value->y2) || (value->y1) >= value->y2)
	{
		my_mlx_pixel_put(&mlx_ut->img, (int)x, value->y1, value->color1);
		x = ((value->y1 - value->b) / value->a) + 0.5;
		if (value->y1 < value->y2)
			value->y1++;
		else if (value->y1 > value->y2)
			value->y1--;
		else
		{
			my_mlx_pixel_put(&mlx_ut->img, (int)x, value->y1, value->color1);
			break ;
		}
	}
}

void	bresenham_y_dsc(t_utils *mlx_ut, t_bresenham *value)
{
	double	x;

	x = (double)value->x1;
	while ((value->y1 <= value->y2) || (value->y1) >= value->y2)
	{
		my_mlx_pixel_put(&mlx_ut->img, (int)x, value->y1, value->color1);
		x = value->x1 + (value->x1 - ((value->y1 - value->b) / value->a) + value->sens);
		if (value->y1 < value->y2)
			value->y1++;
		else if (value->y1 > value->y2)
			value->y1--;
		else
		{
			my_mlx_pixel_put(&mlx_ut->img, (int)x, value->y1, value->color1);
			break ;
		}
	}
}
