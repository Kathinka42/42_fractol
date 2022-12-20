/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_pixel_to_coordinates.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:23:51 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/20 15:34:08 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 	SCALE_PIXEL_TO_COORDINATES
*	----------------------------
*	To be able to apply the mandelbrot fomula to the image, for each pixel
*	the corresponding coordinates on the real and the imaginary axis need to
*	be calculated.
*/

void	scale_pixel_to_coordinates(t_image *image, t_set *set)
{
	double	width_of_axe;
	double	height_of_axe;

	height_of_axe = set->max_imag - set->min_imag;
	width_of_axe = set->max_real - set->min_real;
	set->c_real = width_of_axe * ((double)image->pix_x - WIDTH / 2) / WIDTH;
	set->c_imag = height_of_axe * ((double)image->pix_y - HEIGHT / 2) / HEIGHT;
}
