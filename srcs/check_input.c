/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:02:21 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/19 17:38:30 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	CHECK_INPUT
*	--------------
*	Function distinguishes between input sets. If Julia, it also checks for
*	valid input parameters. If input is valid, function returns 0.
*/

int	check_input(int argc, char **argv, t_image *image)
{
	if	(argc < 2 || argc == 3 || argc > 4)
		return (-1);
	else if (argc == 2 && ft_strncmp(argv[1], "Mandelbrot", 11))
		return (-1);
	printf("argv2: %d\n", param_is_valid(argv[2], image));
	printf("argv3: %d\n", param_is_valid(argv[3], image));
	// if (argc == 4 && !ft_strncmp("Julia", argv[1], 6)
	// 	&& param_is_valid(argv[2], image) && param_is_valid(argv[3], image))
	// 	return (-1);
	return (0);
}
