/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_memory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:43:44 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/17 10:33:54 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ALLOCATE_MEMORY
* ------------------
* allocate memory for all structs within t_image struct
*/

void	allocate_memory(t_image *image)
{	
	image->set = ft_calloc(1, sizeof(t_set));
	if (!image->set)
		return ;
	image->color = ft_calloc(1, sizeof(t_color));
	if (!image->color)
		return ;
}

void	clean_up(t_image *image)
{
	if (image->set)
		free (image->set);
	if (image->color)
		free (image->color);
	if (image->mlx)
	{
		mlx_delete_image(image->mlx, image->g_img);
		mlx_terminate(image->mlx);
	}
	if (image)
		free (image);
	system ("leaks fractol");
	exit (0);
}
