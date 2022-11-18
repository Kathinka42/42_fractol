/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:46:33 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 11:05:44 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_STRCHR
*	-------------
*	DESCRIPTION
*	The function locates the first occurence of c in string str, whereas the
*	terminating null is considered part of the string. Int i is converted to
*	char. The functions strchr() and strrchr() return a pointer to the located
*	character, or NULL if the character does not appear in the string.
*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((char)c == str[i])
		{
			return ((char *) &str[i]);
		}
		i++;
	}
	if (c == 0)
		return ((char *)str + ft_strlen(str));
	return (NULL);
}
