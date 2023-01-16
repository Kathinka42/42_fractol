/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:12:13 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/16 16:08:50 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	FT_ATOF
*	---------
*	Function converts a string in the format xxx.xxxxxx to the corresponding
*	floating point number, using ft_atoi as a helper.
*/
double ft_atof(char *s)
{
	double	res;
	double	res2;
	int		len;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	res = (double)ft_atoi(&s[i]);
	while (s[i] && s[i] != '.')
		i++;
	if (s[i] == '.')
		i++;
	res2 = (double)ft_atoi(&s[i]);
	len = ft_strlen(&s[i]);
	while (len-- > 0)
		res2 /= 10;
	return (res + (res2 * sign));
}

// double	res;
// 	double	res2;
// 	int		len;
// 	int		i;
// 	int		sign;

// 	i = 0;
// 	sign = 1;
// 	while (s[i] == '-' || s[i] == '+')
// 	{
// 		if (s[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	res = (double)ft_atoi(&s[i]);
// 	while (s[i] && s[i] != '.')
// 		i++;
// 	if (s[i] == '.')
// 		i++;
// 	res2 = (double)ft_atoi(&s[i]);
// 	len = ft_strlen(&s[i]);
// 	while (len-- > 0)
// 		res2 /= 10;
// 	return (res + (res2 * sign));
