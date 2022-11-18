/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:44:29 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 11:20:08 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_STRLEN
*	-------------
*	DESCRIPTION
*	The strlen() function computes the length of the string s.  The strnlen()
*	function attempts to compute the length of s, but never scans beyond the
*	first maxlen bytes of s.
*/

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
