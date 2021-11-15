/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 23:01:44 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/16 00:45:49 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*str2;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str2 = malloc(len + 1);
	if (!str2)
		return (0x0);
	while (s1 && s1[i])
	{
		str2[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		str2[i + j] = s2[j];
		j++;
	}
	str2[len] = '\0';
	free(s1);
	return (str2);
}

void	add_lines_to_list(t_lines **lines, char *line_file)
{
	t_lines	*tmp;

	tmp = *lines;
	if (tmp)
	{
		puts("PAS LOUER");
		while (tmp->next != 0x0)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_lines));
		tmp->next->line = line_file;
		tmp->next->next = 0x0;
	}
	else
	{
		puts("SCH");
		tmp = malloc(sizeof(t_lines));
		tmp->line = line_file;
		tmp->next = 0x0;
		*lines = tmp;
	}
}

int	get_next_line(t_lines **lines, int fd)
{
	int res;
	char buffer[2];
	char *line;
	char *new_line;

	if (fd < 0 || fd > 1024)
		return (0);
	res = 1;
	line = 0x0;
	while (res != 0)
	{
		res = read(fd, buffer, 1);
		if (res < 0)
			return (-1);
		buffer[1] = '\0';
		if (buffer[0] == '\n')
		{
			//return(0);
			add_lines_to_list(lines, line);
			line = 0x0;
		}
		else
			line = ft_strjoin(line, buffer);
	}
	return (1);
}