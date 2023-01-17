/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:05:11 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/17 10:43:34 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	CALCULATE_JULIA
*	-------------------------
*	Function calculates the next interation of Z, split up into both a real
*	and an imaginary part.
*	Basic function is Z(n+1) = Z(n)*Z(n) + C, where Z(n+1) is the next
*	iteration. Both, Z and C can be split up in imaginary and real parts, e.g.
*	c = c_imag + c_real.
*	In contrary to the Mandelbrot set, within the Julia set, the parameters of
*	C remain constant and are passed from the user to the command line.
*/

void	calculate_julia(t_set *set)
{
	double	tmp_re;

	tmp_re = set->z_re * set->z_re - set->z_im * set->z_im;
	set->z_im = 2.0 * set->z_re * set->z_im + set->const_im;
	set->z_re = tmp_re + set->const_re;
}

/*	COUNT_ITERATIONS_JULIA
*	-----------------------------
*	Function counts the number of iterations for a particular point in the
*	coordinating system, for which Z remains within the boundaries of the set.
*	In contrary to the Mandelbrot set, Z does not start from the center, but
*	from each individual point in the coordinating system.
*/

int	count_iterations_julia(t_set *set)
{
	set->iter = 0;
	set->z_re = set->c_re;
	set->z_im = set->c_im;
	while (set->iter < set->max_iter
		&& (pow(set->z_re, 2) + pow(set->z_im, 2)) < 4.0)
	{
		calculate_julia(set);
		set->iter++;
	}
	return (set->iter);
}
