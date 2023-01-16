/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:46:38 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/16 12:00:17 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	color_by_iteration(t_image *image)
{
	if (image->set->iter == image->set->max_iter)
		return(get_rgba(0,0,0));
	return (generate_colors(image));
}

void	put_pixel(t_image *image, int pix_x, int pix_y)
{
	int color;

	color = color_by_iteration(image);
	mlx_put_pixel(image->g_img, pix_x, pix_y, color);
}

int   generate_colors(t_image *image)
{
    t_set	*set;
    t_color *color;
	double  ratio;
    double  ratio_reciprocal;
    int colors[3];
	
	set = image->set;
    color = image->color;
    ratio = (double)set->iter / (double)set->max_iter;
    ratio_reciprocal = 1.0 - ratio;
    colors[0] = 9 * (ratio * ratio * ratio) * ratio_reciprocal * 255;
    colors[1] = 15 * (ratio * ratio) * (ratio_reciprocal * ratio_reciprocal) \
				* 255;
    colors[2] = 9 * ratio * (ratio_reciprocal * ratio_reciprocal \
				* ratio_reciprocal) * 255;
    return  (get_rgba(colors[color->i], colors[color->j], colors[color->k]));
}

int change_color(t_image *image)
{
	t_color *color;

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