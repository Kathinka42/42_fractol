/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:02:21 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/13 09:48:11 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	CHECK_INPUT
*	--------------
*	Function distinguishes between input sets. If Julia, it also checks for
*	valid input parameters. If input is not valid, function calls clean up
*	function from where it exits the program.
*/

int	check_input(int argc, char **argv, t_image *image)
{
	image->mlx = NULL;
	if (argc == 2 && !ft_strncmp(argv[1], "Mandelbrot", 11))
		image->set->settype = 1;
	else if (argc == 4 && !ft_strncmp(argv[1], "Julia", 6)
		&& param_is_valid(argv[2]) && param_is_valid(argv[3]))
		image->set->settype = 2;
	else
	{
		print_instructions();
		clean_up(image);
	}
	return (0);
}
