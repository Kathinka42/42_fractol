/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_pixel_to_coordinates.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:23:51 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/20 15:09:07 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 	SCALE_PIXEL_TO_COORDINATES
*	----------------------------
*	To be able to apply the mandelbrot fomula to the image, for each pixel
*	the corresponding coordinates on the real and the imaginary axis need to
*	be calculated.
*/

void	scale_pixel_to_coordinates(t_image *image)
{
	double width_of_axe;
	double height_of_axe;
	// probably initialize somewhere else, depending on set;
	image->set->max_imag = 2.0;
	image->set->max_real = 2.0;
	image->set->min_imag = -2.0;
	image->set->min_real = -2.0;

	height_of_axe = image->set->max_imag - image->set->min_imag;
	width_of_axe = image->set->max_real - image->set->min_real;

	// height_of_axe = image->coordinates->imag_y_max - image->coordinates->imag_y_min;
	// width_of_axe = image->coordinates->x_max - image->coordinates->x_min;

	// point->x = len_of_axe * ((double)x - WIDTH/2) / WIDTH;
	// point->y = height_of_axe * ((double)y - HEIGHT/2) / HEIGHT;

	image->set->c_real = width_of_axe * ((double)image->pixel->x - WIDTH / 2) / WIDTH;
	image->set->c_imag = height_of_axe * ((double)image->pixel->y - HEIGHT / 2) / HEIGHT;
	// if (image->pixel->x == 200 && image->pixel->y == 200)
	// {
	// 	printf("REAL %f\n", image->set->c_real);
	// 	printf("Imaginary %f\n\n", image->set->c_imag);
	// }
}


	