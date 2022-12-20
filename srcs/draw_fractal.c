/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:45:38 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/20 15:11:12 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	DRAW_FRACTOL
*	-------------
*	
*/

void	draw_fractal(t_image *image)
{
	int iter = 0;
	image->pixel->x = 0;
	image->pixel->y = 0;
	// exit (0);
	while (image->pixel->x < WIDTH)
	{
		image->pixel->y = 0;
		printf("%d\n", image->pixel->x);
		// exit(0);
		
		while (image->pixel->y < HEIGHT)
		{
			scale_pixel_to_coordinates(image);
			iter = count_iterations(image);
			printf("%d\n", iter);
			if (iter < image->set->max_iter)
				mlx_put_pixel(image->g_img, image->pixel->x , image->pixel->y, get_rgba(0, 0, 0 , 255));
			//put_color(image, iter);
			image->pixel->y++;
		}
		image->pixel->x++;
	}
}