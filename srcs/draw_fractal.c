/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:45:38 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/13 13:22:45 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	DRAW_FRACTAL
*	-------------
*	Central function of the program. The function iterates through each pixel in
*	the window. To be able to apply the mandelbrot fomula to the image, for each
*	pixel the corresponding coordinates on the real and the imaginary axis need
*	to be calculated.
 calculate the number of iterations for each point and put
*	a particular color to it.
*/

void	draw_fractal(t_image *image)
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
			image->set->iter = count_iterations(image->set);
			put_pixel(image, pix_x, pix_y);
			pix_x++;
		}
		pix_y++;
	}
	// mlx_image_to_window(image->mlx, image->g_img, pix_x, pix_y);
}