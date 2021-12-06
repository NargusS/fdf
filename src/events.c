/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:51:37 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:22:17 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_key(int keycode, t_utils *mlx)
{
	int	status;

	status = 2;
	if (keycode == 65307)
		close_all(mlx);
	else if (keycode == 51 && status--)
		mlx->coef_z += 1;
	else if (keycode == 52 && status--)
		mlx->coef_z -= 1;
	else if (keycode == 97 && status--)
		mlx->scale_x += 10;
	else if (keycode == 100 && status--)
		mlx->scale_x -= 10;
	else if (keycode == 119 && status--)
		mlx->scale_y += 10;
	else if (keycode == 115 && status--)
		mlx->scale_y -= 10;
	if (status == 1)
		render(mlx);
	return (0);
}

int	mouse_code(int keycode, int x, int y, t_utils *mlx)
{
	int	status;

	status = 2;
	if (keycode == 4 && status--)
		mlx->zoom += 1;
	else if (keycode == 5 && mlx->zoom > 1 && status--)
		mlx->zoom -= 1;
	if (status == 1)
		render(mlx);
	return (0);
}

void	fdf(t_utils *mlx_utils)
{
	fdf_init(mlx_utils);
	render(mlx_utils);
	mlx_mouse_hook(mlx_utils->window, &mouse_code, mlx_utils);
	mlx_key_hook(mlx_utils->window, &get_key, mlx_utils);
	mlx_loop(mlx_utils->mlx);
}

void	render(t_utils *mlx)
{
	my_clear_img(&mlx->img);
	print_map(mlx, mlx->points);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img.img, 0, 0);
}
