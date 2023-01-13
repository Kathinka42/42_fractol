/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:14:09 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/13 14:58:51 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	CALCULATE_MANDELBROT
*	-------------------------
*	Function calculates the next interation of Z, split up into both a real
*	and an imaginary part.
*	Basic function is Z(n+1) = Z(n)*Z(n) + C, where Z(n+1) is the next
*	iteration. Both, Z and C can be split up in imaginary and real parts, e.g.
*	c = c_imag + c_real.
*	c_imag and c_real are equal to the point in the coordinating system on which
*	the iteration is executed and are input parameters to the count iterations
*	function.
*/

void	calculate_mandelbrot(t_set *set)
{
	double	tmp_im;

	tmp_im = 2 * set->z_re * set->z_im + set->c_im;
	set->z_re = pow(set->z_re, 2) - pow(set->z_im, 2) + set->c_re;
	set->z_im = tmp_im;
}

/*	COUNT_ITERATIONS_MANDELBROT
*	-----------------------------
*	Function counts the number of iterations for a particular point in the
*	coordinating system, for which Z remains within the boundaries of the set.
*	Z always starts from the center (0,0). This is the major difference to the
*	Julia set.
*/

int	count_iterations_mandelbrot(t_set *set)
{
	set->iter = 0;
	set->z_re = 0.0;
	set->z_im = 0.0;
	while (set->iter < set->max_iter
			&& (pow(set->z_re, 2) + pow(set->z_im, 2)) < 4.0)
	{
		calculate_mandelbrot(set);
		set->iter++;
	}
	return (set->iter);
}
