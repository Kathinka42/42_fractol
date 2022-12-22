/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:40:16 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/22 14:33:15 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_set(t_set *set)
{
	set->iter = 0;
	set->max_iter = 0;
	set->max_imag = 2.0;
	set->max_real = 2.0;
	set->min_imag = -2.0;
	set->min_real = -2.0;
	// set->new_height = set->max_imag - set->min_imag;
	// set->new_width = set->max_real - set->min_real;
}