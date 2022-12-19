/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_iterations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:14:09 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/19 17:50:56 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	power_of_2(double k)
{
	return (k * k);
}

void	calculate_next_iteration(t_image *image)
{
	image->set->z_imag = 2 * image->set->z_real * image->set->z_imag + power_of_2(image->set->z_real) + power_of_2(image->set->z_imag) + image->set->c_imag + image->set->c_real;
	image->set->z_real = power_of_2(image->set->z_real) + image->set->c_imag;
}


/*	COUNT_ITERATIONS
*	function returns, if Z goes out of the set. Its result determines, if a
*	certain point is within the set, at the border or outside the set.
*/
int	count_iterations(t_image *image)
{
	image->set->count = 0;
	image->set->iter = 50;
	image->set->z_real = 0;
	image->set->z_imag = 0;
	image->set->c_real = 0;
	image->set->c_imag = 0;
	
	while (image->set->count < image->set->iter)
	{
		image->set->z_sq_real = power_of_2(image->set->z_real);
		image->set->z_sq_imag = power_of_2(image->set->z_imag);
		
		if(sqrt(image->set->z_sq_real + image->set->z_sq_imag) > 2)
			break;
			
		image->set->count++;
		calculate_next_iteration(image);
	}
	return (image->set->count);
}