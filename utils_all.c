/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:17:50 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/01 20:28:09 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int		get_width_line(t_point *pts)
{
	int	width;

	width = 0;
	while (pts[width].is_end != 1)
		width++;
	return (width + 1);
}

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*p_adrr;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		p_adrr = data->adrr + \
		(y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int *)p_adrr = (unsigned int)color;
	}
}

int	abs_value(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	get_value_base(char *base, char elem)
{
	int i;

	i = 0;
	while (base && base[i])
	{
		if (base[i] == elem)
			return (i);
		i++;
	}
	return (-1);
}

int	atoi_base(char *str, char *base)
{
	int	num;
	int value_base;

	num = 0;
	while (str && *str)
	{
		if (*str != '-')
		{
			value_base = get_value_base(base, *str);
			if (value_base == -1 && str[0] != '-')
				return (num);
			else if (value_base == -1 && str[0] == '-')
				return (-num);
			else
				num = (num * 10) + value_base;
		}
		str++;
	}
	if (str && str[0] != '-')
		return (num);
	else
		return (-num);
}