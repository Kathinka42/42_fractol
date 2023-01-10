/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:43:44 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/10 14:38:48 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ALLOCATE_MEMORY
* ------------------
* allocate memory for all structs within t_image struct
*/

void	allocate_memory(t_image *image)
{	
	image->coordinates = ft_calloc(1, sizeof(t_coordinates));
	if (!image->coordinates)
		return ;
	image->set = ft_calloc(1, sizeof(t_set));
	if (!image->set)
		return ;
}
