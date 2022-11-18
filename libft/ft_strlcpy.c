/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:23:48 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 11:18:33 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_STRLCPY
*	-------------
*	DESCRIPTION
*	The function strlcpy() takes the full size of the destination buffer and
*	guarantees NUL-termination if there is room.  Note that room for the NUL
*	should be included in dstsize. strlcpy() copies up to dstsize - 1
*	characters from the string src to dst, NUL-terminating the result if
*	dstsize is not 0.
*	Case distinction:
*	- if src < dst -> copy full src string (incl. '\0');
*	- if src > dst -> copy as many bytes possible from src + add '\0';
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < dstsize)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	return (srclen);
}
