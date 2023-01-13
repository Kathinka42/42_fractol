/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:05:11 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/13 10:33:51 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_julia(t_set *set)
{
	double tmp_re;

	tmp_re = set->z_re * set->z_re - set->z_im * set->z_im;
	set->z_im = 2 * set->z_re * set->z_im + set->const_im;
	set->z_re = tmp_re + set->const_re;
}

int	count_iterations_julia(t_set *set)
{
	set->iter = 0;
	set->z_re = 0.0;
	set->z_im = 0.0;
	while (set->iter < set->max_iter
			&& (pow(set->z_re, 2) + pow(set->z_im, 2)) < 4.0)
	{
		calculate_julia(set);
		set->iter++;
	}
	return (set->iter);
}
