/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_scroll.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:54:21 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/16 14:21:29 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>

/* MOUSE_SCROLL
* ---------------
* Currently only placeholder; does not yet produce the required result.
* Functionality of the mouse wheel is to zoom in and out within the limits
* of the computer.
*/

void mouse_scroll(double xdelta, double ydelta, mlx_image_t *g_img, mlx_t *mlx)
{
	// Simple up or down detection.
	if (ydelta > 0)
		// g_img = mlx_new_image(mlx, 150, 150);
		puts("Up!");
	else if (ydelta < 0)
		puts("Down!");
	
	// Can also detect a mousewheel that go along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");
}
