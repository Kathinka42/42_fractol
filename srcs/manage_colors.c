/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:46:38 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/17 09:56:24 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	GET_RGBA
*	----------
*	Function combines four individual channel bytes into a single integer using
*	bit-shifting. The last byte is for transparency and always set to 255.
*/

uint32_t	get_rgba(uint8_t red, uint8_t green, uint8_t blue)
{
	return ((uint32_t)(red << 24 | green << 16 | blue << 8 | 255));
}

/*	COLOR_BY_ITERATION
*	-------------------
*	It the number of iterations equals the number of max_iterations, the point
*	lies within the set and is colored in black. Other the function calls
*	generate_color to generate a color based on the number of iterations.
*/

uint32_t	color_by_iteration(t_image *image)
{
	if (image->set->iter == image->set->max_iter)
		return (get_rgba(0, 0, 0));
	return (generate_colors(image));
}

/*	PUT_PIXEL
*	------------
*	Function puts the pixel in a specific color on the screen.
*/

void	put_pixel(t_image *image, int pix_x, int pix_y)
{
	int	color;

	color = color_by_iteration(image);
	mlx_put_pixel(image->g_img, pix_x, pix_y, color);
}

/*	GENERATE_COLORS
*	----------------
*	Function calculates three values, one for r, one for g, one for b and
*	combines them into one color, using the get_rgba function. The values for r
*	g and b are calculated based on the number of iterations in relation to the
*	number of max iterations.
*/

int	generate_colors(t_image *image)
{
	t_set	*set;
	t_color	*color;
	double	ratio;
	double	ratio_reciprocal;
	int		colors[3];

	set = image->set;
	color = image->color;
	ratio = (double)set->iter / (double)set->max_iter;
	ratio_reciprocal = 1.0 - ratio;
	colors[0] = 9 * (ratio * ratio * ratio) * ratio_reciprocal * 255;
	colors[1] = 15 * (ratio * ratio) * (ratio_reciprocal * ratio_reciprocal) \
				* 255;
	colors[2] = 9 * ratio * (ratio_reciprocal * ratio_reciprocal \
				* ratio_reciprocal) * 255;
	return (get_rgba(colors[color->i], colors[color->j], colors[color->k]));
}

/*	CHANGE_COLOR
*	--------------
*	The function exchanges the values (= order) of the three color components
*	that are used by the generate_colors function.
*/

int	change_color(t_image *image)
{
	t_color	*color;

	color = image->color;
	if (image->set->settype == 2)
		return (1);
	if (color->i < 2)
	{
		if (color->j < 2)
		{
			if (color->k < 2)
				return (color->k++);
			return (color->j++);
		}
		color->j = 0;
		color->k = 0;
		return (color->i++);
	}
	color->i = 0;
	return (1);
}
