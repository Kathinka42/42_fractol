/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:27:34 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 10:22:48 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_MEMSET
*	-----------
*	DESCRIPTION
*	The function writes len bytes of value c (converted to an unsigned
*	char) to the string str1. Void pointer can't dereferenced, therefore a new
*	pointer needs to be created, which points to the same address like str1.
*	Empty string is not being considered and leads to segfault.
*/

#include "libft.h"

void	*ft_memset(void *str1, int c, size_t len)
{
	size_t			i;
	unsigned char	*str2;

	i = 0;
	str2 = (unsigned char *)str1;
	while (i < len)
	{
		str2[i] = (unsigned char) c;
		i++;
	}
	return (str1);
}
