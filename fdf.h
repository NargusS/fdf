/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achane-l <achane-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:01:04 by achane-l          #+#    #+#             */
/*   Updated: 2021/12/01 19:58:07 by achane-l         ###   ########.fr       */
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
#define BLUE 0xFF07ACFF
#define WHITE 16777215

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
	t_point		**points;
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

// init struct
void	bresenham_init(t_utils *mlx_ut, t_bresenham *values, t_point start, t_point end);
void	fdf_init(t_utils *mlx_utils);

// Algorithm for trace line
void	ln_no_bre(t_utils *mlx_ut, t_bresenham *value);
void	bresenham_x(t_utils *mlx_ut, t_bresenham *value);
void	bresenham_y(t_utils *mlx_ut, t_bresenham *value);
void	bresenham_x_dsc(t_utils *mlx_ut, t_bresenham *value);
void	bresenham_y_dsc(t_utils *mlx_ut, t_bresenham *value);

//Config_view

void	scale(t_bresenham *values, t_point start, t_point end, t_utils *mlx_ut);
void	get_scale(t_utils *mlx, t_point **pts, int x, int y);
void	altitude(t_bresenham *values, t_point start, t_point end, int altitude);
void	zoom(t_bresenham *values, t_point start, t_point end, int zoom);
void	isometric_projection(t_utils *mlx_ut, int *x, int *y, int z);

//print map
void	print_map(t_utils *mlx_utils, t_point **points);
void	drw_ln(t_utils *mlx_ut, t_bresenham *values);
void	render(t_utils *mlx);

//read map
t_point	**read_map(char *file_path, t_utils *mlx_utils);

//utils all
void	free_points(t_point ***points, int height);
int		get_width_line(t_point *pts);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	init_tab(char ***tab_str, int tab_size);
int		abs_value(int value);

//utils read
char	**ft_split(char *line);
void	init_tab(char ***tab_str, int tab_size);
void	free_tab_str(char ***tab_str, int i);

int	atoi_base(char *str, char *base);
int	get_value_base(char *base, char elem);
#endif