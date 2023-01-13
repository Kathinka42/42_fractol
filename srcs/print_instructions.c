/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:14:08 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/13 09:30:45 by kczichow         ###   ########.fr       */
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
	write(1, "Use: ./fractol followed by\n", 28);
	write(1, "\n", 1);
	write(1, "- [Mandelbrot] for Mandelbrot set\n", 34);
	write(1, "- [Julia] [num.num] [num.num] for Julia set, where [num.num] is\
	a floating point number with '.' as delimeter\n", 110);
	write(1, "\n", 1);
	write(1, "For [Mandelbrot] no additional parameters possible\n", 51);
	write(1, "For [Julia] either none or 2 parameters possible\n", 50);
	write(1, "\n", 1);
	write(1, "Example: ./fractol Mandelbrot\n", 30);
	write(1, "Example: ./fractol Julia −0.4 0.6\n", 36);
}