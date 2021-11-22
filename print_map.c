/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:37 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/22 20:22:48 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric_projection(int *x, int *y, int z)
{
	*x = (*x - *y) * cos(0.523599);
	*y = (*x + *y) * sin(0.523599) - z;
}

void	print_map(t_utils *m_u, t_point **pts)
{
	int x;
	int	y;

	y = 0;
	while (y < m_u->height)
	{
		x = 0;
		while (pts[y][x].is_end != 1)
		{
			if (pts[y][x].is_end != 1)
				drw_ln(m_u, pts[y][x].x, pts[y][x].y, pts[y][x + 1].x, pts[y][x + 1].y, pts);
			if (y < m_u->height - 1)
				drw_ln(m_u, pts[y][x].x, pts[y][x].y, pts[y + 1][x].x, pts[y + 1][x].y, pts);
			x++;
		}
		if (pts[y][x].is_end == 1 && y < m_u->height - 1)
			drw_ln(m_u, pts[y][x].x, pts[y][x].y, pts[y + 1][x].x, pts[y + 1][x].y, pts);
		y++;
	}
}