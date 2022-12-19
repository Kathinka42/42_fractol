/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_pixel_to_coordinates.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:23:51 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/19 17:49:58 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 	SCALE_PIXEL_TO_COORDINATES
*	----------------------------
*	Calculates the matrix for the input set (-2,-2) to (2,2) for Mandelbrot
*	from pixel set (eg. 800 x 800).
*/

void	scale_pixel_to_coordinates(t_image *image)
{
	
	// probably initialize somewhere else, depending on set;
	image->coordinates->imag_y_max = 2;
	image->coordinates->x_max = 2;
	image->coordinates->imag_y_min = -2;
	image->coordinates->x_min = -2;

	image->coordinates->x = image->coordinates->x_max - image->coordinates->x_min / WIDTH * image->pixel->x;
	image->coordinates->imag_y = image->coordinates->imag_y_max - image->coordinates->imag_y_min / HEIGHT * (HEIGHT - image->pixel->y);
}
	