/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:52:04 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 11:30:36 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_STRRCHR
*	-------------
*	DESCRIPTION
*	The function locates the last occurence of c in string str, whereas the
*	terminating null is considered part of the string; int i is converted to
*	char. The functions strchr() and strrchr() return a pointer to the located
*	character, or NULL if the character does not appear in the string.
*	The function iterates through the entire string, setting a counter to
*	the length of the string. It then searches the string backwards and
*	returns the first occurence of the character.
*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if ((char)c == str[i])
		{
			return ((char *) &str[i]);
		}
	i--;
	}
	if (c == 0)
		return ((char *)str + ft_strlen(str));
	return (NULL);
}
