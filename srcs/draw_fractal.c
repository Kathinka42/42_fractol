/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:45:38 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/19 17:51:32 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_image *image)
{
	int iter = 0;
	image->pixel->x = 0;
	image->pixel->y = 0;
	while (image->pixel->x <= WIDTH)
	{
		//printf("%f\n", image->pixel->x);
		image->pixel->y = 0;
		while (image->pixel->y <= HEIGHT)
		{
			scale_pixel_to_coordinates(image);
			iter = count_iterations(image);
			//put_color(image, iter);
			mlx_put_pixel(image->g_img, image->coordinates->x , image->coordinates->imag_y, get_rgba(255, 0, 255 , 255));
			image->pixel->y++;
		}
		image->pixel->x++;
	}
}