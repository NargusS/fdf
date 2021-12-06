/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:09:58 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:22:59 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*p_adrr;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		p_adrr = data->adrr + \
		(y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)p_adrr = (unsigned int)color;
	}
}

void	my_clear_img(t_img_data *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			my_mlx_pixel_put(img, x++, y, DEFAULT);
		y++;
	}
}

void	close_all(t_utils *mlx)
{
	free_my_stack(&mlx->color_grad);
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx->window = NULL;
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	free_points(&mlx->points, mlx->height);
	exit(EXIT_SUCCESS);
}
