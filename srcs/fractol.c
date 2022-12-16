/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:54:21 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/16 15:14:04 by kczichow         ###   ########.fr       */
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

void	fractol(char **argv, t_var *var)
{
	mlx_t	*mlx;
		
	//if (var->settype == 1)
	mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int32_t));

	//mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // clean up once the application requests an exit
	//mandelbrot();
	mlx_terminate(mlx);
	return ;
}


/*	MAIN
*	---------
* To make use of the MLX42 library and to access all the functions, the correct
* header needs to be included, then the structure variables must be initialized
* to connect the main handle. The init function creates the window.
*/ 

int main (int argc, char **argv)
{
	t_var *var;

	var = malloc(sizeof(var));
	if (!var)
		return (0);
	init_variables(var);
	if (check_input(argc, argv, var))
		fractol(argv, var);
		
	return (0);
}