/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:01:04 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/15 16:05:20 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct  s_utils
{
    void    *mlx;
    void    *window;
    int     count;
    int     x1;
    int     y1;
    int     x2;
    int     y2;
}               t_utils;

void	drw_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);
void	asc_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);
void	dsc_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);
void	cst_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);

#endif