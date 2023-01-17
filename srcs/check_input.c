/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:02:21 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/17 10:41:51 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	FT_ATOF
*	---------
*	Function converts a string in the format xxx.xxxxxx to the corresponding
*	floating point number, using ft_atoi as a helper.
*/
double	ft_atof(char *str)
{
	double	res;
	double	res2;
	int		len;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = (double)ft_atoi(&str[i]);
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.')
		i++;
	res2 = (double)ft_atoi(&str[i]);
	len = ft_strlen(&str[i]);
	while (len-- > 0)
		res2 /= 10;
	return (res + (res2 * sign));
}

/*	PARAM_IS_VALID
*	----------------
*	Function is used for input checking of the Julia set. The parameters are
*	floating point numbers that need the specifit format (-)x.y. If the format
*	is correct, the function returns 0.
*/

int	param_is_valid(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '+' || s[i] == '-')
			i++;
		if (s[i] >= '0' && s[i] <= '9')
		{
			i++;
			if (s[i] == '.')
			{
				i++;
				if (s[i] >= '0' && s[i] <= '9')
				{
					i++;
					return (-1);
				}
			}
		}
	i++;
	}
	return (0);
}

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
