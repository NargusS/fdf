/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:33:32 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/22 00:36:46 by achane-l         ###   ########.fr       */
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

static int	str_append(char **str, char carac)
{
	char	*new_str;
	int		len;

	if (carac == 'm')
		return(-1);
	len = (int)ft_strlen(*str);
	new_str = malloc(len + 2);
	if (new_str == NULL)
		return (-1);
	new_str[len + 1] = 0;
	new_str[len] = carac;
	while (*str && len > 0)
	{
		new_str[len - 1] = (*str)[len - 1];
		len--;
	}
	if (*str)
		free(*str);
	*str = new_str;
}

char	**ft_split(char *line)
{
	char	**tab_str;
	int		nb_words;
	int		i;

	i = 0;
	nb_words = count_words(line);
	tab_str = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (tab_str == NULL)
		return (NULL);
	init_tab(&tab_str, nb_words + 1);
	while (line && *line)
	{
		if (*line != ' ')
		{
			if (str_append(&tab_str[i], *line) == -1)
			{
				free_tab_str(&tab_str, i);
				return (NULL);
			}
		}
		else if (*line == ' ' && tab_str[i] != NULL)
			i++;
		line++;
	}
	return (tab_str);
}

void	init_tab(char ***tab_str, int tab_size)
{
	int	i;

	i = 0;
	while (i < tab_size)
	{
		(*tab_str)[i] = NULL;
		i++;
	}
}

void	free_tab_str(char ***tab_str, int i)
{
	if (i < 0)
	{
		i = 0;
		while ((*tab_str)[i])
		{
			if ((*tab_str)[i])
				free((*tab_str)[i++]);
			else
				i++;
		}
	}
	else
	{
		while (i >= 0)
		{
			if ((*tab_str)[i])
				free((*tab_str)[i--]);
			else
				i--;
		}
	}
	if (*tab_str)
		free((*tab_str));
}

void	free_points(t_point ***points, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if ((*points)[i])
			free((*points)[i++]);
		else
			i++;
	}
	if ((*points))
		free((*points));
}
