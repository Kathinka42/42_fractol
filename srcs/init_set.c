/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:40:16 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/10 15:16:08 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_set(t_set *set)
{
	set->iter = 0;
	set->max_iter = 0;
	set->max_im = 2.0;
	set->max_re = 2.0;
	set->min_im = -2.0;
	set->min_re = -2.0;
	set->i = 0;
	set->j = 1;
	set->k = 2;
	set->height_of_axe = set->max_im - set->min_im;
	set->width_of_axe = set->max_re - set->min_re;
	set->coef_im = set->height_of_axe / HEIGHT;
	set->coef_re = set->width_of_axe / WIDTH;
}
