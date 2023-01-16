/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:14:48 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/16 17:05:43 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	mlx_t	*mlx;
	t_image *image;
	t_set	*set;
	
	image = param;
	set = image->set;
	mlx = image->mlx;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		clean_up(image);
	if (keydata.key == MLX_KEY_P && keydata.action == MLX_PRESS)
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
