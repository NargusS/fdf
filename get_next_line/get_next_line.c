/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:17:06 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/17 17:22:00 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, int character)
{
	int	i;

	i = 0;
	while (str[i] != (char)character)
	{
		if (str[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

char	*get_line(char *save)
{
	int		i;
	char	*new_line;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;
	new_line = ft_substr(save, 0, i);
	return (new_line);
}

char	*get_save(char *save)
{
	char	*new_save;
	int		save_size;
	int		i;

	i = 0;
	save_size = ft_strlen(save);
	new_save = NULL;
	while (save[i] != '\n' && save[i])
		i++;
	if (save[i] == '\n' && save[i + 1] != 0)
		new_save = ft_substr(save, i + 1, save_size - i);
	free(save);
	save = NULL;
	return (new_save);
}

int	returned_and_assign(char **save, char **line, int res)
{
	*line = get_line(*save);
	*save = get_save(*save);
	if (res == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	int			res;

	if (fd < 0 || line == NULL)
		return (-1);
	res = 1;
	if (!save)
		save = ft_strdup("");
	while (ft_strchr(save, '\n') == 0 && res != 0)
	{
		res = read(fd, buffer, BUFFER_SIZE);
		if (res < 0)
		{
			free(save);
			return (-1);
		}
		buffer[res] = 0;
		temp = ft_strjoin(save, buffer);
		free(save);
		save = temp;
	}
	return (returned_and_assign(&save, line, res));
}