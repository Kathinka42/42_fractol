/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:05:11 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/13 13:57:05 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_set *set)
{
	double tmp_re;

	tmp_re = set->z_re * set->z_re - set->z_im * set->z_im;
	set->z_im = 2 * set->z_re * set->z_im + set->const_im;
	set->z_re = tmp_re + set->const_re;
}

int	count_iterations_julia(t_set *set)
{
	set->iter = 0;
	set->z_re = set->c_re;
	set->z_im = set->c_im;
	while (set->iter < set->max_iter
			&& (pow(set->z_re, 2) + pow(set->z_im, 2)) < 4.0)
	{
		calculate_julia(set);
		set->iter++;
	}
	return (set->iter);
}

void	draw_julia(t_image *image)
{
	int pix_x;
	int pix_y;
	
	image->set->iter = 0;
	// change_color(image->set);
	
	pix_y = 0;
	while (pix_y < HEIGHT)
	{
		pix_x = 0;
		image->set->c_im = image->set->max_im - pix_y * image->set->coef_im;

		while (pix_x < WIDTH)
		{
			image->set->c_re = image->set->min_re + pix_x * image->set->coef_re;
			image->set->iter = count_iterations_julia(image->set);
			// image->set->iter = count_iterations(image->set);
			put_pixel(image, pix_x, pix_y);
			pix_x++;
		}
		pix_y++;
	}
	// mlx_image_to_window(image->mlx, image->g_img, pix_x, pix_y);
}