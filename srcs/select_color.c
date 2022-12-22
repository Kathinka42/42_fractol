/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:46:38 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/22 14:39:26 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int n)
{
	int color[10];

	color[0] = 0x00F08080;
	
}

// int get_rgba(int r, int g, int b, int a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }


int	select_color(int iter, t_image *image)
{
	if (iter == image->set->max_iter)
		return (get_rgba(0,0,0,255);
	return (get_rgba(255, 255, 0, 255));
}

//greenbriar: 4b9b69