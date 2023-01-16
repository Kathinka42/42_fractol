/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:57:33 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/16 16:48:47 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_up(t_image *image)
{
	if (image->set)
		free (image->set);
	if (image->color)	
		free (image->color);
	if (image)
		free (image);
	if (image->mlx)
	{
		mlx_delete_image(image->mlx, image->g_img);
		mlx_terminate(image->mlx);
	}
	system ("leaks fractol");
	exit (0);
}
