/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:40:16 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/16 17:07:22 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_parameters(t_image *image)
{
	t_set	*set;

	set = image->set;
	set->iter = 0;
	set->max_iter = 200;
	set->max_im = 2.0;
	set->max_re = 2.0;
	set->min_im = -2.0;
	set->min_re = -2.0;
	set->height_of_axe = set->max_im - set->min_im;
	set->width_of_axe = set->max_re - set->min_re;
	set->coef_im = set->height_of_axe / HEIGHT;
	set->coef_re = set->width_of_axe / WIDTH;
	set->const_re = -0.0;
	set->const_im = 0.8;
}

void	init_julia(t_set *set, char *floating1, char *floating2)
{
	set->const_re = ft_atof(floating1);
	set->const_im = ft_atof(floating2);
}

void	init_color(t_color *color)
{
	color->r	= 0;
	color->g	= 0;
	color->b	= 0;
	color->i	= 0;
	color->j	= 1;
	color->k	= 2;
}

void	init_set(int argc, char **argv, t_image *image)
{
	if (image->set->settype == 1)
	{
	image->mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", true);
	if (!image->mlx)
		exit(EXIT_FAILURE);
	}
	if (image->set->settype == 2)
	{
	image->mlx = mlx_init(WIDTH, HEIGHT, "Julia", true);
	if (!image->mlx)
		exit(EXIT_FAILURE);
	}
	init_color(image->color);
	init_parameters(image);
	if (image->set->settype ==2)
		init_julia(image->set, argv[2], argv[3]);
}
