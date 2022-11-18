/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:35:23 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 11:22:57 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_STRMAPI
*	-------------
*	DESCRIPTION
*	The strmapi() function applies the function ’f’ to each character of the
*	string ’s’, and passing its index as first argument to create a new string
*	(with malloc(3)) resulting from successive applications of ’f’.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	res = ft_strdup(s);
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
