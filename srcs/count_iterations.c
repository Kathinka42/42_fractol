/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_iterations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:14:09 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/20 15:50:37 by kczichow         ###   ########.fr       */
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
	double	tmp_imag;

	tmp_imag = 2 * set->z_real * set->z_imag + set->c_imag;
	set->z_real = pow(set->z_real, 2) - pow(set->z_imag, 2) + set->c_real;
	set->z_imag = tmp_imag;
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
	set->max_iter = 50;
	set->z_real = 0.0;
	set->z_imag = 0.0;
	while (set->iter < set->max_iter)
	{
		if (sqrt((pow(set->z_real, 2) + pow(set->z_imag, 2))) > 2)
			return (set->iter);
		calculate_next_iteration(set);
		set->iter++;
	}
	return (set->iter);
}
