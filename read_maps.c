/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:53:29 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/01 20:27:53 by achane-l         ###   ########.fr       */
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

static int	get_my_color(char *values)
{
	int i;

	i = 0;
	while (values && values[i])
	{
		if (values[i] == ',')
			return (atoi_base(values + i + 3, "0123456789ABCDEF"));
		i++;
	}
	return (WHITE);
}

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
		(*my_point)[x].z = atoi_base(tab_str[x], "0123456789");
		(*my_point)[x].color = get_my_color(tab_str[x]);
		if (x == width - 1)
			(*my_point)[x].is_end = 1;
		else
			(*my_point)[x].is_end = 0;
		x++;
	}
	free_tab_str(&tab_str, -1);
	return (0);
}

static int	add_value(char *file_path, t_point **points, t_utils *mlx_u)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	y = 0;
	while (y < mlx_u->height)
	{
		get_next_line(fd, &line);
		points[y] = NULL;
		if (parse_value(&(points[y]), y, line) == -1)
		{
			if (line)
				free(line);
			return (-1);
		}
		free(line);
		y++;
	}
	return (0);
}

t_point	**read_map(char *file_path, t_utils *mlx_utils)
{
	t_point	**points;
	int		i;

	if (open(file_path, O_DIRECTORY) > 0)
		return (NULL);
	mlx_utils->height = get_height(file_path);
	if (mlx_utils->height <= 0)
		return (NULL);
	else
	{
		points = malloc(sizeof(t_point *) * (mlx_utils->height));
		if (points == NULL)
			return (NULL);
		i = 0;
		while (i < mlx_utils->height)
			points[i++] = NULL;
		if (add_value(file_path, points, mlx_utils) == -1)
		{
			free_points(&points, mlx_utils->height);
			return (NULL);
		}
		return (points);
	}
	return (NULL);
}
