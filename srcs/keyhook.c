/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:14:48 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/17 10:44:20 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	MY_KEYHOOK
*	------------
*	function is called by MLX lib function and specifies the actions to be
*	executed, if a particular key is being pressed. Void parameter has to be
*	assigned.
*	Press esc: clean up function is called: window closes + pointers freed.
*	Press m: switch to mandelbrot 
*	Press j: switch to julia
*	Press c: change color
*/

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;
	t_image	*image;
	t_set	*set;

	image = param;
	set = image->set;
	mlx = image->mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		clean_up(image);
	if (keydata.key == MLX_KEY_C && keydata.action == MLX_PRESS)
	{
		change_color(image);
		draw_fractal(image);
	}
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		image->set->settype = 1;
		draw_fractal(image);
	}
	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
	{
		image->set->settype = 2;
		draw_fractal(image);
	}
}

/*	MY_HOOK
*	---------
*	Generic hook. Different way to assign functionality to keys. In this
*	function, image can be moved within the window by using the arrow keys.
*/

void	my_hook(void *param)
{
	t_image	*image;

	image = param;
	if (mlx_is_key_down(image->mlx, MLX_KEY_UP))
		image->g_img->instances[0].y -= 5;
	if (mlx_is_key_down(image->mlx, MLX_KEY_DOWN))
		image->g_img->instances[0].y += 5;
	if (mlx_is_key_down(image->mlx, MLX_KEY_LEFT))
		image->g_img->instances[0].x -= 5;
	if (mlx_is_key_down(image->mlx, MLX_KEY_RIGHT))
		image->g_img->instances[0].x += 5;
}
