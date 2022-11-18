/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:08:52 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 09:56:36 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_MEMCMP
*	-----------
*	DESCRIPTION
*	The function compares byte string s1 against byte string s2. Both strings
*	are assumed to be n bytes long. The function returns zero if the two
*	strings are identical, otherwise returns the difference between the first
*	two differing bytes (treated as unsigned char values, so that `\200' is
*	greater than `\0', for example). Zero-length strings are always identical.
*	The const void input variables need to be casted into strings first in
*	order to perform the operation.
*/

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t	n)
{
	size_t			i;
	unsigned char	*str3;
	unsigned char	*str4;

	str3 = (unsigned char *) str1;
	str4 = (unsigned char *) str2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (str3[i] != str4[i])
			return (str3[i] - str4[i]);
		i++;
	}
	return (0);
}
