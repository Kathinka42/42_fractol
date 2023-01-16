/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:33:12 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/16 12:01:18 by kczichow         ###   ########.fr       */
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
#include <complex.h>

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
	double	const_re;
	double	const_im;
	double	min_im;
	double	max_im;
	double	min_re;
	double	max_re;
	double	coef_im;
	double	coef_re;
	double	height_of_axe;
	double	width_of_axe;
}	t_set;

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
	int		i;
	int		j;
	int		k;
}	t_color;

typedef struct s_image
{
	mlx_t			*mlx;
	mlx_image_t		*g_img;
	t_set			*set;
	t_color			*color;
}	t_image;

# ifndef WIDTH
#  define WIDTH 800
# endif

# ifndef HEIGHT
#  define HEIGHT 800
# endif

// input checking
int		check_input(int argc, char **argv, t_image *image);
int		param_is_valid(char *s);
void	allocate_memory(t_image *image);
void	init_set(int argc, char **argv, t_image *image);
void	print_instructions(void);
double ft_atof(char *str);

void		draw_fractal(t_image *image);
int			count_iterations_julia(t_set *set);
int			count_iterations_mandelbrot(t_set *set);

void		mandelbrot();
void		fractol(char **argv, t_image *image);
int			select_color(int iter, t_image *image);
uint32_t	get_rgba(uint8_t red, uint8_t green, uint8_t blue);
int   		generate_colors(t_image *image);
int			change_color(t_image *image);
void		put_pixel(t_image *image, int pix_x, int pix_y);
uint32_t	color_by_iteration(t_image *image);

// events

void mouse_scroll(double xdelta, double ydelta, mlx_image_t *g_img, mlx_t *mlx);
void my_scrollhook(double xdelta, double ydelta, void *param);
void	my_keyhook(mlx_key_data_t keydata, void *param);

void	clean_up(t_image *image);

// temporary test functions
void	draw_circle(mlx_image_t *g_img, mlx_t *mlx, int xc, int yc, int x, int y);
void	circleBres(mlx_image_t *g_img, mlx_t *mlx);
void	draw_square(mlx_image_t	*g_img, mlx_t *mlx, int x, int y);
void	draw_line(mlx_image_t	*g_img, mlx_t *mlx);

#endif