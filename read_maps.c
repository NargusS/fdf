/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:53:29 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/17 20:35:36 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_height(char *file_path)
{
	char	*line;
	int		fd;
	int		height;
	int		ret;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	height = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
		{
			close (fd);
			return (-1);
		}
		else if (ret > 0 || (ret == 0 && line && line[0] != 0))
			height++;
		free(line);
	}
	close(fd);
	return (height);
}

static int	get_width(char **tab_str)
{
	int		width;

	if (tab_str != NULL)
	{
		width = 0;
		while (tab_str[width])
			width++;
		return (width);
	}
	return (-1);
}

// static t_point	**add_value(char *file_path, t_point **points, t_utils *mlx_u)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;
// 	char	**tab_str;
// 	int		j;

// 	fd = open(file_path, O_RDONLY);
// 	if (fd < 0)
// 		return (NULL);
// 	i = 0;
// 	while (i < mlx_u->height)
// 	{
// 		get_next_line(fd, &line);
// 		// tab_str = ft_split(line);
// 		// points[i] = malloc(sizeof(t_point) * get_width(tab_str));
// 		// if (points[i] == NULL)
// 		// {
// 		// 	free_tab_str(&tab_str, -1);
// 		// 	while (i > 0)
// 		// 	{
// 		// 		free(points[i-1]);
// 		// 		i--;
// 		// 	}
// 		// 	return (NULL);
// 		// }
// 		j = 0;
// 		while (j < get_width(tab_str))
// 		{
// 			// printf("%p\n", points[i][j]);
// 			points[i][j].x = j;
// 			points[i][j].y = i;
// 			points[i][j].z = atoi(tab_str[j]);
// 			// if (ft_strchr(tab_str[j], ','))
// 			// 	points[i][j].color = 
// 			j++;
// 		}
// 		free_tab_str(&tab_str, -1);
// 		i++;
// 	}
// 	return (points);
// }

static int	parse_value(t_point **my_point, int y, char *line)
{
	int		x;
	int		width;
	char	**tab_str;

	tab_str = ft_split(line);
	if (tab_str == NULL)
		return (-1);
	width = get_width(tab_str);
	(*my_point) = malloc(sizeof(t_point) * width);
	if (*my_point == NULL)
	{
		free_tab_str(&tab_str, -1);
		return (-1);
	}
	x = 0;
	while (x < width)
	{
		(*my_point)[x].x = x;
		(*my_point)[x].y = y;
		(*my_point)[x].z = atoi(tab_str[x]);
		x++;
	}
	free_tab_str(&tab_str, -1);
	return (0);
}

static	void	add_value(char *file_path, t_point **points, t_utils *mlx_u)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return ;
	y = 0;
	while (y < mlx_u->height)
	{
		get_next_line(fd, &line);
		if (parse_value(&points[y], y, line) == -1)
		{
			if (line)
				free(line);
			while (y >= 0)
			{
				if (points[y])
					free(points[y]);
				y--;
			}
			return ;
		}
		y++;
		free(line);
	}
	return ;
}

t_point	**read_map(char *file_path, t_utils *mlx_utils)
{
	t_point	**points;

	if (open(file_path, O_DIRECTORY) > 0)
		return (NULL);
	mlx_utils->height = get_height(file_path);
	if (mlx_utils->height <= 0)
		return (NULL);
	else
	{
		points = malloc(sizeof(t_point **) * (mlx_utils->height));
		if (points == NULL)
			return (NULL);
		add_value(file_path, points, mlx_utils);
		return (points);
	}
	return (NULL);
}
