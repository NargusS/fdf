/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:01:04 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/16 00:21:40 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
typedef struct  s_lines
{
    char            *line;
    struct s_lines  *next;
}               t_lines;

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

void	add_lines_to_list(t_lines **lines, char *line_file);
int	get_next_line(t_lines **lines, int fd);
void	drw_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);
void	asc_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);
void	dsc_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);
void	cst_ln(t_utils *mlx_ut, int x1, int y1, int x2, int y2);

#endif