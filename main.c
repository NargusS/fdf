/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:02:53 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/22 00:36:56 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minilibx-linux/mlx.h"
#include "fdf.h"


// static int test(int button, int x, int y, t_utils *mlx_u)
// {
// 	write(1, "CLICK\n", 6);
// 	if (mlx_u->count == 0)
// 	{
// 		mlx_u->x1 = x;
// 		mlx_u->y1 = y;
// 		mlx_u->count++;
// 	}
// 	else if (mlx_u->count == 1)
// 	{
// 		mlx_u->x2 = x;
// 		mlx_u->y2 = y;
// 		mlx_u->count = 0;
// 		drw_ln(mlx_u,mlx_u->x1,mlx_u->y1, mlx_u->x2,mlx_u->y2);
// 	}
// 	return 0;
// }

/*int	main()
{
	t_utils	mlx_utils;

	mlx_utils.mlx = mlx_init();
	mlx_utils.window = mlx_new_window(mlx_utils.mlx, 1000, 1000, "test");
	mlx_utils.count = 0;
	//mlx_pixel_put(mlx_utils.mlx, mlx_utils.window,100, 900,0xFFFCFF33);
	//drw_ln(&mlx_utils,900,100,100, 900);
	mlx_mouse_hook(mlx_utils.window, &test, &mlx_utils);
	mlx_loop(mlx_utils.mlx);
	return (0);
}*/

int main()
{
	t_utils mlx_utils;
	t_point **test;
	char **tab_str;

	// mlx_utils.mlx = mlx_init();
	// mlx_utils.window = mlx_new_window(mlx_utils.mlx, 1000, 1000, "test");
	// test = read_map("maps/test_maps/pyramide.fdf", &mlx_utils);
	// if (test)
	// 	printf("%d\n", test[17][11].z);
	// else
	// 	printf("%p\n", test);dee
	// free_points(&test, mlx_utils.height);
	// mlx_loop(mlx_utils.mlx);
	tab_str = ft_split("test de la mort");
	int i = 0;
	while (tab_str!=NULL && tab_str[i])
		printf("%s\n", tab_str[i++]);
	if (tab_str)
		free_tab_str(&tab_str, -1);
	// int i=0;
	// if (tab_str)
	// {
	// 	while (tab_str[i])
	// 	{
	// 		printf("%s\n", tab_str[i]);
	// 		i++;
	// 	}
	// 	free_tab_str(&tab_str, -1);
	// 	//free(tab_str);
	// }
	return (0);
}
