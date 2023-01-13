/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:12:13 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/13 13:47:59 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	FT_ATOF
*	---------
*	Function converts a string in the format xxx.xxxxxx to the corresponding
*	floating point number, using ft_atoi as a helper.
*/
double ft_atof(char *str)
{
	double result;
	double result2;
	int i;
	int count;
	
	result = (double)ft_atoi(str);
	result2 = 0;
	i = 0;
	count = 0;
	while (str[i+1])
		i++;
	while (ft_isdigit(str[i]))
		i--;
	i++;
	while (ft_isdigit(str[i]))
	{
		result2 = result2 * 10 + str[i] - '0';
		i++;
		count++;
	}
	result2 = result2 / pow(10, count);
	if (result < 0)
		return (result - result2);
	return (result + result2);
}
