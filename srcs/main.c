/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:56:33 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/11 10:57:52 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>

static mlx_image_t	*g_img;

// void my_keyhook(mlx_key_data_t keydata, void *param)
// {
// 	// If we PRESS the 'J' key, print "Hello".
// 	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
// 		puts("Hello ");

// 	// If we RELEASE the 'K' key, print "World".
// 	if (keydata.key == MLX_KEY_K && keydata.action == MLX_RELEASE)
// 		puts("World");

// 	// If we HOLD the 'L' key, print "!".
// 	if (keydata.key == MLX_KEY_L && keydata.action == MLX_REPEAT)
// 		puts("!");
	
// 	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE && keydata.modifier == MLX_CONTROL)
// 		puts("Gotta grab it all!");
// }

// void my_scrollhook(double xdelta, double ydelta, t_image *image)
// {
// 	// Simple up or down detection.
// 	if (ydelta > 0)
// 		puts("Up!");
// 		// g_img->instances[0].y -= 5;
// 		// g_img->instances[0] -= g_img->instances * 0.9;

// 	else if (ydelta < 0)
// 		puts("Down!");
	
// 	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
// 	if (xdelta < 0)
// 		puts("Sliiiide to the left!");
// 	else if (xdelta > 0)
// 		puts("Sliiiide to the right!");
// }

// left side key = 0;
// right side key = 1;
// wheel key = 2;
// for scrolling use scrollhook
// int mouse_key, int action, int modifier_key, 
void	my_mousehook(mouse_key_t button, action_t action, modifier_key_t mods, mlx_t *mlx)
{
	int x;
	int y;
	
	if (button == 0 && action == MLX_PRESS)
		printf("Hello from mouse_hook!\n");
	if (button == 0 && action == MLX_RELEASE)
		mlx_get_mouse_pos(mlx, &x, &y);
		// printf("Hello from mouse_hook!\n");
	if (button == 1)
		printf("Hey\n");
}

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img->instances[0].x += 5;
}



//Find out how the memset function works in this context;

// int32_t	main (void)
// {
// 	mlx_t	*mlx;
	
// 	mlx = mlx_init(WIDTH, HEIGHT, "My first window", true);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	mlx_key_hook(mlx, &my_keyhook, NULL);
// 	mlx_mouse_hook(mlx, &my_mousehook, NULL);
// 	mlx_scroll_hook(mlx, &my_scrollhook, NULL);
// 	g_img = mlx_new_image(mlx, 800, 800);
// 	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int32_t));
	
// 	draw_line(g_img, mlx);

// 	//mlx_put_pixel(g_img, 20 , 20, get_rgba(153, 150, 150 , 0));
	
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_delete_image(mlx, g_img); // clean up once the application requests an exit
// 	//mandelbrot();
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

// int main (int argc, char **argv)
// {
	// t_image *image;

	// image = malloc(sizeof(t_image));
	// if (!image)
	// 	return (0);
	// allocate_memory(image);
	// init_set(image->set);
	// fractol(argv, image);
	// select_color(21, image);
// 	return (0);
// }