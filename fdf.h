/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:01:04 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/22 00:21:23 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "minilibx-linux/mlx.h"
typedef struct  s_point
{
    int     x;
    int     y;
    int     z;
    float   angle;
    int     color;
}               t_point;

typedef struct  s_utils
{
    void    *mlx;
    void    *window;
    int     height;
    int     width;
}               t_utils;

char	**ft_split(char *line);
t_point	**read_map(char *file_path, t_utils *mlx_utils);
void	init_tab(char ***tab_str, int tab_size);
void	free_tab_str(char ***tab_str, int i);
void	free_points(t_point ***points, int height);
void	drw_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);
void	asc_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);
void	dsc_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);
void	cst_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);

#endif