/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:45:38 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/17 09:27:20 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	DRAW_FRACTAL
*	-------------
*	The function iterates through each pixel in the window. To be able to apply
*	the mandelbrot or julia formula to the image, for each pixel the
*	corresponding coordinates on the real and the imaginary axis need to be
*	calculated.
*	Then, the program calculates the number of iterations for each point and
*	puts a particular color to it.
*/

void	draw_fractal(t_image *image)
{
	int	pix_x;
	int	pix_y;

	image->set->iter = 0;
	pix_y = 0;
	while (pix_y < HEIGHT)
	{
		pix_x = 0;
		image->set->c_im = image->set->max_im - pix_y * image->set->coef_im;
		while (pix_x < WIDTH)
		{
			image->set->c_re = image->set->min_re + pix_x * image->set->coef_re;
			if (image->set->settype == 1)
				image->set->iter = count_iterations_mandelbrot(image->set);
			else if (image->set->settype == 2)
				image->set->iter = count_iterations_julia(image->set);
			put_pixel(image, pix_x, pix_y);
			pix_x++;
		}
		pix_y++;
	}
}
