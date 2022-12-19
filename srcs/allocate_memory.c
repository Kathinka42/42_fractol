/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:43:44 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/19 17:40:06 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ALLOCATE_MEMORY
* ------------------
* allocate memory for all structs within t_image struct
*/

void	allocate_memory(t_image *image)
{	
	image->pixel = ft_calloc(1, sizeof(t_pixel));
	if (!image->pixel)
		return ;
	image->coordinates = ft_calloc(1, sizeof(t_coordinates));
	if (!image->coordinates)
		return ;
	image->set = ft_calloc(1, sizeof(t_set));
	if (!image->set)
		return ;
}
