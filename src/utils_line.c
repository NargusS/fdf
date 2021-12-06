/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 07:59:39 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:20:53 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ln_no_bre_x(t_utils *mlx_ut, t_bresenham *value)
{
	while (value->x1 <= value->x2 || value->x1 >= value->x2)
	{
		my_mlx_pixel_put(&mlx_ut->img, value->x1, value->y1, \
		choose_color(mlx_ut, value->color1));
		if (value->x1 < value->x2)
			value->x1++;
		else if (value->x1 > value->x2)
			value->x1--;
		else
		{
			my_mlx_pixel_put(&mlx_ut->img, value->x1, value->y1, \
			choose_color(mlx_ut, value->color1));
			break ;
		}
	}
}

void	ln_no_bre_y(t_utils *mlx_ut, t_bresenham *value)
{
	while (value->y1 <= value->y2 || value->y1 >= value->y2)
	{
		my_mlx_pixel_put(&mlx_ut->img, value->x1, value->y1, \
		choose_color(mlx_ut, value->color1));
		if (value->y1 < value->y2)
			value->y1++;
		else if (value->y1 > value->y2)
			value->y1--;
		else
		{
			my_mlx_pixel_put(&mlx_ut->img, value->x1, value->y1, \
			choose_color(mlx_ut, value->color1));
			break ;
		}
	}
}

int	choose_line_tp(t_utils *mlx_ut, t_bresenham *value)
{
	if (value->dx == 0 || value->dy == 0)
		return (0);
	else if (value->y1 > value->y2 && value->x1 < value->x2)
	{
		if (value->y1 >= value->y2)
			value->sens = 1.0;
		else
			value->sens = -0.5;
		return (-1);
	}
	else if (value->y1 < value->y2 && value->x1 > value->x2)
	{
		if (value->x1 >= value->x2)
			value->sens = 1.0;
		else
			value->sens = -0.5;
		return (-1);
	}
	else
		value->sens = 0.5;
	return (1);
}
