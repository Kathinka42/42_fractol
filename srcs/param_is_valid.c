/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:16:19 by kczichow          #+#    #+#             */
/*   Updated: 2023/01/10 15:18:39 by kczichow         ###   ########.fr       */
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
					return (0);
				}
			}
		}
	i++;
	}
	return (-1);
}
