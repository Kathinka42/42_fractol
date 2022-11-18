/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:57:57 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 11:24:07 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_STRNCMP
*	-------------
*	DESCRIPTION
*	The function lexicographically compares n characters of two strings.
*	Lexicographically bigger or smaller depends on the order in the alphabet
*	(a<b);
*/

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < (n - 1)) && str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] == str2[i])
		i++;
		else
			return ((unsigned char)str1[i] - (unsigned char) str2[i]);
	}
	return ((unsigned char) str1[i] - (unsigned char) str2[i]);
}
