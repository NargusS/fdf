/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:01:04 by achane-l          #+#    #+#             */
/*   Updated: 2021/11/28 22:54:08 by achane-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "get_next_line/get_next_line.h"
#include "minilibx-linux/mlx.h"
# define HEIGHT 1000
# define WIDTH 1000
typedef struct  s_point
{
	int     x;
	int     y;
	int     z;
	int     color;
	int		is_end;
}               t_point;

typedef struct	s_img_data
{
	void	*img;
	void	*adrr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct  s_utils
{
	void    	*mlx;
	void    	*window;
	t_img_data	img;
	int     	height;
	int     	width;
	int     	zoom;
	int     	scale_x;
	int     	scale_y;
	int			coef_z;
	double  	angle_x;
	double		angle_y;
}               t_utils;

typedef struct	s_bresenham
{
	int x1;
	int y1;
	int	z1;
	int color1;
	int	x2;
	int	y2;
	int z2;
	int color2;
	int dx;
	int dy;
	double a;
	double b;
	double	sens;
}				t_bresenham;

int	abs_value(int value);
char	**ft_split(char *line);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	bresenham_x(t_utils *mlx_ut, t_bresenham *value);
void	bresenham_y(t_utils *mlx_ut, t_bresenham *value);
void	bresenham_x_dsc(t_utils *mlx_ut, t_bresenham *value);
void	bresenham_y_dsc(t_utils *mlx_ut, t_bresenham *value);
void	isometric_projection(t_utils *mlx_ut, int *x, int *y, int z);
void	print_map(t_utils *mlx_utils, t_point **points);
t_point	**read_map(char *file_path, t_utils *mlx_utils);
void	init_tab(char ***tab_str, int tab_size);
void	free_tab_str(char ***tab_str, int i);
void	free_points(t_point ***points, int height);
void	drw_ln(t_utils *mlx_ut, t_bresenham *values);
void	bresenham_init(t_utils *mlx_ut, t_bresenham *values, t_point start, t_point end);
void	ln_no_bre(t_utils *mlx_ut, t_bresenham *value);
void	asc_ln(t_utils *mlx_ut, t_bresenham *value);

#endif