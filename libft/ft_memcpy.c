/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:35:12 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 10:17:54 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_MEMCPY
*	-----------
*	DESCRIPTION
*	The function function copies n bytes from memory area src to memory area
*	dst. If dst and src overlap, behavior is undefined, use ft_memmove instead.
*	Void pointer cannot be dereferenced. Therefore new pointer is being created
*	which point to the same address.
*/

#include "libft.h"

void	*ft_memcpy(void *dst1, const void *src1, size_t n)
{
	unsigned char		*dst;
	unsigned const char	*src;
	size_t				i;

	i = 0;
	if (dst1 == NULL && src1 == NULL)
		return (NULL);
	dst = (unsigned char *)dst1;
	src = (unsigned const char *) src1;
	while (i < n)
	{
		dst[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst1);
}
