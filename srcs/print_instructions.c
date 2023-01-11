/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:14:08 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/11 13:59:31 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	PRINT_INSTRUCTIONS
*	-------------------
*	Paramters to create different sets are passed on the command line.
*	If no parameter is provided, or if the parameter is invalid, the program
*	displays a list of available parameters and exits properly.
*/

void	print_instructions(void)
{
	write(1, "\n", 1);
	write(1, "-> Use: ./fractol followed by\n", 31);
	write(1, "\n", 1);
	write(1, "  - [Mandelbrot] for Mandelbrot set\n", 36);
	write(1, "  - [Julia] [num.num] [num.num] for Julia set\n", 46);
	write(1, "    [num.num] is a floating point number ('.' - delimeter).\n", 56);
	write(1, "\n", 1);
	write(1, "For [Mandelbrot] NO additional parameters possible\n", 51);
	write(1, "For [Julia] either none OR 2 parameters possible.\n", 50);
	write(1, "\n", 1);
	write(1, "-> Example: ./fractol Mandelbrot\n", 33);
	write(1, "-> Example: ./fractol Julia −0.4 0.6\n", 39);
}