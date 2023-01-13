/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:57:33 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/13 09:46:23 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_up(t_image *image)
{
	free (image->set);
	free (image);
	if (image->mlx)
	{
		mlx_delete_image(image->mlx, image->g_img);
		mlx_terminate(image->mlx);
	}
	system ("leaks fractol");
	exit (0);
}
