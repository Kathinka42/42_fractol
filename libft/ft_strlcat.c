/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:19:54 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 11:15:53 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_STRLCAT
*	-------------
*	DESCRIPTION
*	The function function appends string src to the end of dst. It will append
*	at most dstsize - strlen(dst) - 1 characters. It will then NUL- terminate,
*	unless dstsize is 0 or the original dst string was longer than dstsize
*	(in practice this should not happen as it means that either dstsize is
*	incorrect or that dst is not a proper string).
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destlen >= dstsize)
		return (dstsize + srclen);
	while (src[i] && (destlen + i) < (dstsize - 1))
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
