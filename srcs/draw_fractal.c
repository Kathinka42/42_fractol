/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:45:38 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/20 15:54:12 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	DRAW_FRACTOL
*	-------------
*	Central function of the program. The function iterates through each pixel in
*	the window. It calls the function respectively to apply a coordinate to each
*	of the pixels, calculate the number of iterations for each point and put
*	a particular color to it.
*/

void	draw_fractal(t_image *image)
{
	int iter;
	
	iter = 0;
	image->pix_x = 0;
	while (image->pix_x < WIDTH)
	{
		image->pix_y = 0;
		
		while (image->pix_y < HEIGHT)
		{
			scale_pixel_to_coordinates(image, image->set);
			iter = count_iterations(image->set);
			if (iter < image->set->max_iter)
				mlx_put_pixel(image->g_img, image->pix_x , image->pix_y, get_rgba(0, 0, 0 , 255));
			//put_color(image, iter);
			image->pix_y++;
		}
		image->pix_x++;
	}
}