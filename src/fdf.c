/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:02:53 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:44:56 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static	int	check_type_file(char *file, char *file_ext)
{
	int	i;
	int	j;

	i = 0;
	while (file && (file[i] && file[i] != '.'))
		i++;
	if (file[i] == '.')
	{
		j = 0;
		while ((file[i] && file_ext[j]) && (file[i] == file_ext[j]))
		{
			i++;
			j++;
		}
		if (file[i] == '\0' && file_ext[j] == '\0')
			return (0);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_utils	mlx_utils;

	if (argc != 2)
	{
		write(1, "Wrong Argument !!!\n", 19);
		exit(EXIT_FAILURE);
	}
	else if (check_type_file(argv[1], ".fdf") == -1)
	{
		write(1, "Wrong file type !!!\n", 20);
		exit(EXIT_FAILURE);
	}
	mlx_utils.points = read_map(argv[1], &mlx_utils);
	if (mlx_utils.points != NULL && \
		check_valid_map(mlx_utils.height, mlx_utils.points) == 1)
		fdf(&mlx_utils);
	else
	{
		if (mlx_utils.points != NULL)
			free_points(&mlx_utils.points, mlx_utils.height);
		write(1, "Problem with map !!!\n", 21);
	}
	return (0);
}
