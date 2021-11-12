/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:02:53 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/12 18:32:00 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fdf.h"
#include <stdio.h>
int test(t_utils *mlx_u)
{
	int x = 0;
	int y = 0;
	puts("rentrer");
	mlx_mouse_get_pos(mlx_u->mlx, mlx_u->window, &x, &y);
	printf("x : %d y: %d\n", x, y);
	write(1, "CLICK", 5);
	return(0);
}

int	main()
{
	t_utils	mlx_utils;

	mlx_utils.mlx = mlx_init();
	mlx_utils.window = mlx_new_window(mlx_utils.mlx, 1000, 1000, "test");
	mlx_pixel_put(mlx_utils.mlx, mlx_utils.window,100, 900,0xFFFCFF33);
	//drw_ln(&mlx_utils,900,100,100, 900);
	int x, y = 0;
	//mlx_mouse_get_pos(mlx_utils.mlx, mlx_utils.window, &x, &y);
	mlx_mouse_hook(mlx_utils.window, &test, (void *)&mlx_utils);
	mlx_loop(mlx_utils.mlx);
	return (0);
}