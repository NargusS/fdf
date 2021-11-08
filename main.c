/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:02:53 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/08 09:57:09 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fdf.h"
#include <stdio.h>
int	main()
{
	t_utils	mlx_utils;
	int i;

	i = 1;
	mlx_utils.mlx = mlx_init();
	mlx_utils.window = mlx_new_window(mlx_utils.mlx, 1000, 1000, "test");
	drw_ln(&mlx_utils, 904, 56, 54, 854);
	mlx_loop(mlx_utils.mlx);
}