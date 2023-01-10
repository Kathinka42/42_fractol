/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:33:12 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/10 15:44:45 by kczichow         ###   ########.fr       */
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
	int	max_iter;
	int iter;
	double	zoom;
	double	z_re;
	double	z_im;
	double	c_re;
	double	c_im;
	double	z_sq_re;
	double	z_sq_im;
	double	min_im;
	double	max_im;
	double	min_re;
	double	max_re;
	double	coef_im;
	double	coef_re;
	double	height_of_axe;
	double	width_of_axe;
	double	new_height;
	double	new_width;
	double	r;
	double	g;
	double	b;
	double	a;
	int		i;
	int		j;
	int		k;
}	t_set;

typedef struct s_coordinates
{
	double	imag_y_max; // max_imag
	double	imag_y_min; // min_imag
	double	x_min; // min_real
	double	x_max; // max_real
	double	x;	// not used
	double	imag_y; //not used
	double	z;
}t_coordinates;

typedef struct s_image
{
	mlx_t			*mlx;
	mlx_image_t		*g_img;
	t_set			*set;
	t_coordinates	*coordinates;
	// int				i;
}t_image;

# ifndef WIDTH
#  define WIDTH 800
# endif

# ifndef HEIGHT
#  define HEIGHT 800
# endif

// input checking
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		check_input(int argc, char **argv, t_image *image);
int		param_is_valid(char *s, t_image *image);
void	allocate_memory(t_image *image);
void	init_set(t_set *set);

void		draw_fractal(t_image *image);
int			count_iterations(t_set *set);

void		mandelbrot();
void		fractol(char **argv, t_image *image);
int			select_color(int iter, t_image *image);
uint32_t	get_rgba(uint8_t red, uint8_t green, uint8_t blue);
uint32_t    generate_colors(t_image *image);
void		put_pixel(t_image *image, int x, int y);

// events

void mouse_scroll(double xdelta, double ydelta, mlx_image_t *g_img, mlx_t *mlx);
void my_scrollhook(double xdelta, double ydelta, void *param);

// temporary test functions
void	draw_circle(mlx_image_t *g_img, mlx_t *mlx, int xc, int yc, int x, int y);
void	circleBres(mlx_image_t *g_img, mlx_t *mlx);
void	draw_square(mlx_image_t	*g_img, mlx_t *mlx, int x, int y);
void	draw_line(mlx_image_t	*g_img, mlx_t *mlx);

#endif