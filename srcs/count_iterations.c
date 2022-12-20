/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_iterations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:14:09 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/20 15:09:42 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_next_iteration(t_image *image)
{
	double	tmp_imag;
	
	tmp_imag = 2 * image->set->z_real * image->set->z_imag + image->set->c_imag;
	image->set->z_real = pow(image->set->z_real, 2) - pow(image->set->z_imag, 2) + image->set->c_real;
	image->set->z_imag = tmp_imag;
	// image->set->z_real = image->set->z_real * image->set->z_real - image->set->z_imag *image->set->z_imag + image->set->c_real;

	// printf("z_imag : %f\n", image->set->z_imag);
	// printf("z_real : %f\n", image->set->z_real);
}


/*	COUNT_ITERATIONS
*	function breaks, if Z goes out of the set. Its result determines, if a
*	certain point is within the set(count = max_iter), at the border or outside
*	the set.
*/
int	count_iterations(t_image *image)
{
	image->set->iter = 0;
	image->set->max_iter = 50;
	image->set->z_real = 0.0;
	image->set->z_imag = 0.0;
	
	// printf("iter is%d\n", image->set->iter);
	// printf("max_iter is%d\n", image->set->max_iter);
	while (image->set->iter < image->set->max_iter)
	{
		if(sqrt((pow(image->set->z_real, 2) + pow(image->set->z_imag, 2))) > 2)
			return (image->set->iter);
		calculate_next_iteration(image);
		image->set->iter++;
		// printf("%d\n", image->set->iter);
	}
	// printf("%d\n", image->set->iter);
	return (image->set->iter);
}