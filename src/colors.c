/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:02:33 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/06 19:22:00 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_my_color(char *values)
{
	int	i;

	i = 0;
	while (values && values[i])
	{
		if (values[i] == ',')
		{
			while (values[i] && values[i] != 'x')
				i++;
			if (values[i] == 'x')
				return (atoi_base(values + i + 1, "0123456789ABCDEF"));
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

int	choose_color(t_utils *mlx_ut, int color_choose)
{
	int	color;

	if (color_choose != -1)
		return (color_choose);
	else
	{
		color = mlx_ut->color_grad->color;
		mlx_ut->color_grad = mlx_ut->color_grad->next;
		return (color);
	}
}
