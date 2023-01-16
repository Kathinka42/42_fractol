/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:54:21 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/16 11:48:17 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	FRACTOL
*	--------
*	Function creates the image, links the hooks and places the image within the
*	window. It calls the drawing function.
*/

void	fractol(char **argv, t_image *image)
{
	image->g_img = mlx_new_image(image->mlx, WIDTH, HEIGHT);
	memset(image->g_img->pixels, 255, image->g_img->width \
			* image->g_img->height * sizeof(int32_t));
	mlx_key_hook(image->mlx, &my_keyhook, image);
	mlx_scroll_hook(image->mlx, &my_scrollhook, image);
	draw_fractal(image);
	mlx_image_to_window(image->mlx, image->g_img, 0, 0);
	mlx_loop(image->mlx);
	return ;
}

/*	MAIN
*	---------
* The structure variables must be initialized
* to connect the main handle. The init function creates the window.
*/

int	main(int argc, char **argv)
{
	t_image	*image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (0);
	allocate_memory(image);
	check_input(argc, argv, image);
	init_set(argc, argv, image);
	fractol(argv, image);
	// clean_up(image);
	return (0);
}
