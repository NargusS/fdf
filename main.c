/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:02:53 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/23 00:13:22 by achane-l         ###   ########.fr       */
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
	mlx_utils.zoom = 20;
	test = read_map("maps/test_maps/10-2.fdf", &mlx_utils);
	print_map(&mlx_utils, test);
	mlx_loop(mlx_utils.mlx);
	free_points(&test, mlx_utils.height);
	return (0);
}
