/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:06:33 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:44:43 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_tab(char ***tab_str, int tab_size)
{
	int	i;

	i = 0;
	while (i < tab_size)
	{
		(*tab_str)[i] = NULL;
		i++;
	}
}

t_color	*init_colors(void)
{
	t_color	*colors;
	int		i;

	i = 16777215;
	colors = NULL;
	while (i > 16711680)
	{
		add_my_element_to_my_stack(&colors, i);
		i -= 257;
	}
	return (colors);
}

void	bresenham_init(t_utils *mlx_ut, t_bresenham *values, \
t_point start, t_point end)
{
	values->color1 = start.color;
	values->color2 = end.color;
	if (values->color1 == -1 || (values->color1 != -1 && values->color2 == -1))
		values->color1 = -1;
	zoom(values, start, end, mlx_ut->zoom);
	altitude(values, start, end, mlx_ut->coef_z);
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
	mlx_utils->color_grad = init_colors();
	get_scale(mlx_utils, mlx_utils->points, \
	(get_width_line(mlx_utils->points[(mlx_utils->height / 2) - 1]) / 2) - 1, \
	(mlx_utils->height / 2) - 1);
}
