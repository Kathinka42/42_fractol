/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:31:20 by kczichowsky       #+#    #+#             */
/*   Updated: 2022/05/04 11:12:40 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_STRJOIN
*	-------------
*	DESCRIPTION
*	The function allocates (with malloc(3)) and returns a new string, which is
*	the result of the concatenation of ’s1’ and ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	char	*newstring;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	newstring = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (newstring == NULL)
		return (NULL);
	ft_memcpy(newstring, s1, len_s1);
	ft_memcpy((newstring + len_s1), s2, len_s2);
	newstring[len_s1 + len_s2] = '\0';
	return (newstring);
}
