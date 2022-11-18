/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:02:58 by kczichowsky       #+#    #+#             */
/*   Updated: 2022/05/04 11:35:35 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_SUBSTR
*	-------------
*	DESCRIPTION
*	The function allocates (with malloc(3)) and returns a substring from the
*	string ’s’. The substring begins at index ’start’ and is of maximum size
*	’len’.
*/

#include "libft.h"

char	*ft_substr(char const	*s, unsigned int start, size_t	len)
{
	char	*substr;
	size_t	slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return (ft_strdup(""));
	if (slen < len + (size_t)start)
		len = slen - (size_t)start;
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	ft_memcpy((char *)substr, (char *)s + start, len);
	substr[len] = '\0';
	return ((char *)substr);
}
