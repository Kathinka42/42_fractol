/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_iterations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:14:09 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/10 10:06:39 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	CALCULATE_NEXT_ITERATION
*	-------------------------
*	Function calculates the next interation of Z, split up into both the real
*	and the imaginary part.
*	Basis function if Z(n+1) = Z(n)*Z(n) + C, where C = c_imag + c_real,
*	which are the input parameters to the count_iterations function.
*/

void	calculate_next_iteration(t_set *set)
{
	double	tmp_im;

	tmp_im = 2 * set->z_re * set->z_im + set->c_im;
	set->z_re = pow(set->z_re, 2) - pow(set->z_im, 2) + set->c_re;
	set->z_im = tmp_im;
}

/*	COUNT_ITERATIONS
*	-------------------
*	Function counts the number of iterations for a particular point in the
*	coordinate system, for which Z remains within the boundaries of the set.
*	Z alwazs starts from the center (0,0).
*	For readability reasons, some variables are initialized here.
*/

int	count_iterations(t_set *set)
{
	set->iter = 0;
	set->max_iter = 200;
	set->z_re = 0.0;
	set->z_im = 0.0;
	while (set->iter < set->max_iter)
	{
		if (sqrt((pow(set->z_re, 2) + pow(set->z_im, 2))) > 2)
			return (set->iter);
		calculate_next_iteration(set);
		set->iter++;
	}
	return (set->iter);
}
