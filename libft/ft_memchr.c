/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 19:54:48 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 10:21:32 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_MEMCHR
*	-----------
*	DESCRIPTION
*	The function locates the first occurrence of c (converted to an unsigned
*	char) in string s. Void pointer can't dereferenced, therefore a new
*	pointer needs to be created, which points to the same address like str.
*/

#include "libft.h"

void	*ft_memchr(const void	*str, int c, size_t	n)
{
	size_t			i;
	unsigned char	*str2;

	str2 = (unsigned char *) str;
	i = 0;
	while (i < n)
	{
		if (str2[i] == (unsigned char)c)
		{
			return ((unsigned char *) &str2[i]);
		}
		i++;
	}
	return (NULL);
}
