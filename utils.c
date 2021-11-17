/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:33:32 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/17 20:14:00 by achane-l         ###   ########.fr       */
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

	len = (int)ft_strlen(*str);
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

char	**ft_split(char *line)
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

void	free_tab_str(char ***tab_str, int i)
{
	if (i < 0)
	{
		i = 0;
		while ((*tab_str)[i])
			free((*tab_str)[i++]);
	}
	else
	{
		while (i >= 0)
			free((*tab_str)[i--]);
	}
	free((*tab_str));
}
