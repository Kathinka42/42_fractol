/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:40:16 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/13 13:53:56 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandelbrot(t_image *image)
{
	t_set *set;

	set = image->set;
	image->mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", true);
	if (!image->mlx)
		exit(EXIT_FAILURE);
	set->iter = 0;
	set->max_iter = 200;
	set->max_im = 2.0;
	set->max_re = 2.0;
	set->min_im = -2.0;
	set->min_re = -2.0;
	set->i = 0;
	set->j = 1;
	set->k = 2;
	set->height_of_axe = set->max_im - set->min_im;
	set->width_of_axe = set->max_re - set->min_re;
	set->coef_im = set->height_of_axe / HEIGHT;
	set->coef_re = set->width_of_axe / WIDTH;
}

void	init_julia(t_set *set, char *floating1, char *floating2)
{
	set->const_re = ft_atof(floating1);
	set->const_im = ft_atof(floating2);
}

void	init_set(int argc, char **argv, t_image *image)
{
	t_set *set;

	set = image->set;
	set->r = 0;
	set->g	= 0;
	set->b	= 0;
	set->i	= 0;
	set->j	= 0;
	set->k	= 0;
	
	if (image->set->settype == 1)
		init_mandelbrot(image);
	else if (image->set->settype ==2)
	{
		init_julia(image->set, argv[2], argv[3]);
		init_mandelbrot(image);
	}
}


