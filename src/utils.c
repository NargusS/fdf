/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:51:03 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:44:05 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_width_line(t_point *pts)
{
	int	width;

	width = 0;
	while (pts[width].is_end != 1)
		width++;
	return (width + 1);
}

int	get_value_base(char *base, char elem)
{
	int	i;

	i = 0;
	if (elem >= 'a' && elem <= 'z')
		elem = elem - 32;
	while (base && base[i])
	{
		if (base[i] == elem)
			return (i);
		i++;
	}
	return (-1);
}

int	abs_value(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

int	atoi_base(char *str, char *base)
{
	int	num;
	int	value_base;

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

int	check_valid_map(int height, t_point **points)
{
	int	i;
	int	check_map;

	i = 0;
	if (height > 1)
	{
		check_map = get_width_line(points[i]);
		while (i < height)
		{
			if (check_map != get_width_line(points[i]))
				return (-1);
			i++;
		}
		return (1);
	}
	return (-1);
}
