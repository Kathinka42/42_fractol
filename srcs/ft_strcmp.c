/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:25:40 by kczichow          #+#    #+#             */
/*   Updated: 2022/12/16 14:29:00 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../MLX42/include/MLX42/MLX42.h"
#include "fractol.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include <math.h>

/*	FT_STRCMP
*	-------------
*	DESCRIPTION
*	The function lexicographically compares the characters of two strings.
*/

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	
	while (str1[i] && str2[i])
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
	}
	return ((unsigned char) str1[i] - (unsigned char) str2[i]);
}
