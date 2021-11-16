/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:02:53 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/16 23:51:08 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx-linux/mlx.h"
#include "fdf.h"


int test(int button, int x, int y, t_utils *mlx_u)
{
	write(1, "CLICK\n", 6);
	if (mlx_u->count == 0)
	{
		mlx_u->x1 = x;
		mlx_u->y1 = y;
		mlx_u->count++;
	}
	else if (mlx_u->count == 1)
	{
		mlx_u->x2 = x;
		mlx_u->y2 = y;
		mlx_u->count = 0;
		drw_ln(mlx_u,mlx_u->x1,mlx_u->y1, mlx_u->x2,mlx_u->y2);
	}
}

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

static int	get_height(char *file_path)
{
	char	*line;
	int		fd;
	int		height;
	int		ret;


	fd = open(file_path, O_RDONLY);
	height = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (-1);
		else if (ret > 0 || (ret == 0 && line && line[0] != 0))
			height++;
		free(line);
	}
	return (height);
}

int main()
{
	int fd;
	// char **tab;
	// char *test;
	// int i;

	// test = "test de la fonction";
	// tab = ft_split(test);
	// i = 0;
	// while (tab[i])
	// {
	// 	printf("%s\n", tab[i]);
	// 	i++;
	// }
	// i = 0;
	// while (tab[i])
	// 	free(tab[i++]);
	// free(tab);
	printf("%d\n", get_height("maps/test_maps/julia.fdf"));

}