/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:54:21 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/13 13:55:26 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol(char **argv, t_image *image)
{
	//if (var->settype == 1)
	
	image->g_img = mlx_new_image(image->mlx, WIDTH, HEIGHT);
	memset(image->g_img->pixels, 255, image->g_img->width * image->g_img->height * sizeof(int32_t));

	//mlx_loop_hook(mlx, &hook, mlx);
	mlx_key_hook(image->mlx, &my_keyhook, image);
	mlx_scroll_hook(image->mlx, &my_scrollhook, image);
	// draw_fractal(image);
	draw_julia(image);
	//exit(0);
	mlx_image_to_window(image->mlx, image->g_img, 0, 0);
	mlx_loop(image->mlx);
	//mlx_delete_image(image->mlx, image->g_img); // clean up once the application requests an exit
	mlx_terminate(image->mlx);
	return ;
}

/*	MAIN
*	---------
* The structure variables must be initialized
* to connect the main handle. The init function creates the window.
*/ 

int main (int argc, char **argv)
{
	t_image *image;

	image = malloc(sizeof(t_image));
	if (!image)
		return (0);
	allocate_memory(image);
	check_input(argc, argv, image);
	init_set(argc, argv, image);
	fractol(argv, image);
	return (0);
}
