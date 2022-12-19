/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:33:12 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/19 17:50:30 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACTOL_H
# define FRACTOL_H

#include "libft.h"
#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>

typedef struct s_set
{
	int settype;
	int	iter;
	int count;
	double	z_real;
	double	z_imag;
	double	c_real;
	double	c_imag;
	double	z_sq_real;
	double	z_sq_imag;
}	t_set;

typedef struct s_pixel
{
	int	x;
	int	y;
}t_pixel;

typedef struct s_coordinates
{
	double	imag_y_max;
	double	imag_y_min;
	double	x_min;
	double	x_max;
	double	x;
	double	imag_y;
	double	z;
}t_coordinates;

typedef struct s_image
{
	mlx_t			*mlx;
	mlx_image_t		*g_img;
	t_pixel			*pixel;
	t_set			*set;
	t_coordinates	*coordinates;
	int				i;
}t_image;

# ifndef WIDTH
#  define WIDTH 800
# endif

# ifndef HEIGHT
#  define HEIGHT 800
# endif

// input checking
int	ft_strncmp(const char *str1, const char *str2, size_t n);
int	check_input(int argc, char **argv, t_image *image);
int param_is_valid(char *s, t_image *image);
void allocate_memory(t_image *image);

void	draw_fractal(t_image *image);
int	count_iterations(t_image *image);

void	scale_pixel_to_coordinates(t_image *image);
void	mandelbrot();
void	fractol(char **argv, t_image *image);
int get_rgba(int r, int g, int b, int a);

// events

void mouse_scroll(double xdelta, double ydelta, mlx_image_t *g_img, mlx_t *mlx);

// temporary test functions
void	draw_circle(mlx_image_t *g_img, mlx_t *mlx, int xc, int yc, int x, int y);
void	circleBres(mlx_image_t *g_img, mlx_t *mlx);
void	draw_square(mlx_image_t	*g_img, mlx_t *mlx, int x, int y);
void	draw_line(mlx_image_t	*g_img, mlx_t *mlx);

#endif