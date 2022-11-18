/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:57:10 by kczichow          #+#    #+#             */
/*   Updated: 2022/11/11 13:29:56 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_MEMMOVE
*	-----------
*	DESCRIPTION
*	The function copies len bytes from string src to string dst. The two
*	strings may overlap. This is why the function does a case distinction.
*	The copy is always done in a non-destructive manner. The function returns
*	the original value of dst. Void pointer cannot be dereferenced. Therefore
*	new pointer is being created which points to the same address.
*/

#include "libft.h"

void	*ft_memmove(void *dst1, const void *src1, size_t len)
{
	unsigned char		*dst;

	if (dst1 == NULL && src1 == NULL)
		return (NULL);
	dst = (unsigned char *) dst1;
	if (dst < (unsigned char *)src1)
		ft_memcpy(dst1, src1, len);
	else
	{
		while (len > 0)
		{
			dst[len - 1] = ((unsigned char *)src1)[len - 1];
			len--;
		}
	}
	return (dst1);
}
