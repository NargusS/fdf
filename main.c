/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:02:53 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/29 02:30:43 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main()
{
	t_utils mlx_utils;
	t_point **test;
	char **tab_str;

	mlx_utils.mlx = mlx_init();
	mlx_utils.window = mlx_new_window(mlx_utils.mlx, WIDTH, HEIGHT, "test");
	mlx_utils.img.img = mlx_new_image(mlx_utils.mlx, WIDTH, HEIGHT);
	mlx_utils.img.adrr = mlx_get_data_addr(mlx_utils.img.img, &(mlx_utils.img.bits_per_pixel), &(mlx_utils.img.line_length), &(mlx_utils.img.endian));
	mlx_utils.zoom = 20;
	mlx_utils.angle_x = (60 * M_PI)/180;
	mlx_utils.angle_y = (30 * M_PI)/180;
	mlx_utils.coef_z = 0;
	test = read_map("maps/test_maps/elem2.fdf", &mlx_utils);
	print_map(&mlx_utils, test);
	mlx_put_image_to_window(mlx_utils.mlx, mlx_utils.window, mlx_utils.img.img, 0, 0);
	mlx_loop(mlx_utils.mlx);
	free_points(&test, mlx_utils.height);
	return (0);
}
