/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:16:19 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/19 17:47:35 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*	PARAM_IS_VALID
*	----------------
*	Function is used for input checking of the Julia set. The parameters are
*	floating point numbers that need the specifit format (-)x.y. If the format
*	is correct, the function returns 0.
*/

int	param_is_valid(char *s, t_image *image)
{
	image->i = 0;
	while (s[image->i] != '\0')
	{
		if (s[image->i] == '+' || s[image->i] == '-')
			image->i++;
		if (s[image->i] >= '0' && s[image->i] <= '9')
		{
			image->i++;
			if (s[image->i] == '.')
			{
				image->i++;
				if (s[image->i] >= '0' && s[image->i] <= '9')
				{
					image->i++;
					return (0);
				}
			}
		}
	image->i++;
	}
	return (-1);
}
