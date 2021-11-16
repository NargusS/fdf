/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:53:29 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/17 00:29:00 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(char *line)
{
	int	nb_words;
	int	i;

	i = 0;
	nb_words = 0;
	while (line && line[i])
	{
		if (i > 0 && line[i] == ' ' && line[i - 1] != ' ')
			nb_words++;
		i++;
	}
	if (line && i > 0 && line[i] == 0 && line[i - 1] != ' ')
		nb_words++;
	return (nb_words);
}

static void	str_append(char **str, char carac)
{
	char	*new_str;
	int		len;

	len = ft_strlen(*str);
	new_str = malloc(len + 2);
	if (new_str == NULL)
		return ;
	new_str[len + 1] = 0;
	new_str[len] = carac;
	while (*str && len > 0)
	{
		new_str[len - 1] = (*str)[len - 1];
		len--;
	}
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
	*str = new_str;
}

static char	**ft_split(char *line)
{
	char	**tab_str;
	int		nb_words;
	int		i;

	nb_words = count_words(line);
	i = 0;
	tab_str = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (tab_str == NULL)
		return (NULL);
	while (nb_words + 1 > 0)
		tab_str[nb_words--] = NULL;
	while (line && *line)
	{
		if (*line != ' ')
			str_append(&tab_str[i], *line);
		else if (*line == ' ' && tab_str[i] != NULL)
			i++;
		line++;
	}
	if (line && *line == 0 && tab_str[i] != NULL)
		i++;
	tab_str[i] = NULL;
	return (tab_str);
}

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

void	add_value(char *file_path, t_point **points, t_utils *mlx_u)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return;
	i = 0;
	while (i < mlx_u->height)
	{
		
	}
}

void	read_map(char *file_path, t_utils *mlx_utils)
{
	t_point **points;

	if (open(file_path, O_DIRECTORY) > 0)
		return;
	mlx_utils->height = get_height(file_path);
	if (mlx_utils->height <= 0)
		return;
	else
	{
		points = malloc(sizeof(t_point *) * (mlx_utils->height));
		if (points == NULL)
			return;
		add_value(file_path, points, mlx_utils);
	}
}