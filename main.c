/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:02:53 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/23 20:57:27 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main()
{
	t_utils mlx_utils;
	t_point **test;
	char **tab_str;

	mlx_utils.mlx = mlx_init();
	mlx_utils.window = mlx_new_window(mlx_utils.mlx, 1000, 1000, "test");
	mlx_utils.zoom = 15;
	mlx_utils.angle = 0.3;
	mlx_utils.coef_z = 50;
	test = read_map("maps/test_maps/pyramide.fdf", &mlx_utils);
	printf("%d\n", test[20][13].z);
	print_map(&mlx_utils, test);
	mlx_loop(mlx_utils.mlx);
	free_points(&test, mlx_utils.height);
	return (0);
}
