/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:18:06 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/16 16:27:39 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	ZOOM_IN
*	--------
*	Function readjusts the values of the axis.
*/

void	zoom_out(t_image *image)
{
	t_set	*set;

	set = image->set;
	set->max_im = set->max_im * 1.1;
	set->min_im = set->min_im * 1.1;
	set->max_re = set->max_re * 1.1;
	set->min_re = set->min_re * 1.1;
}

/*	ZOOM_OUT
*	----------
*	Function readjusts the values of the axis.
*/

void	zoom_in(t_image *image)
{
	t_set	*set;

	set = image->set;
	set->max_im = set->max_im * 0.9;
	set->min_im = set->min_im * 0.9;
	set->max_re = set->max_re * 0.9;
	set->min_re = set->min_re * 0.9;
}

/*	MY_SCROLLHOOK
*	----------------
*	Function is called by the MLX42 lib function mlx_scroll_hook and specifies
*	the action to perform, when the mousewheel is beinf moved.
*	ydelta > 0 means mousewheel is moved upwards.
*	ydelta < 0 means mousewheel is moved downwards.
*	void *param is assigned to the pointer to the image struct.
*/

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_image	*image;
	t_set	*set;

	image = param;
	set = image->set;
	(void) xdelta;
	if (ydelta > 0)
		zoom_out(image);
	else if (ydelta < 0)
		zoom_in(image);
	set->height_of_axe = set->max_im - set->min_im;
	set->width_of_axe = set->max_re - set->min_re;
	set->coef_im = set->height_of_axe / HEIGHT;
	set->coef_re = set->width_of_axe / WIDTH;
	draw_fractal(image);
}
