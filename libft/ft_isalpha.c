/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:47:38 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 09:32:58 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_ISALPHA
*	-----------
*	DESCRIPTION
*	The function tests for any alphabetic lower or upper character. The value
*	of the argument must be representable as an unsigned char or the value of
*	EOF (end of file). The return value is either 1 (true) or 0 (false).
*	ASCII A = 65, Z = 90; a = 97, z = 122
*	Original function in library <ctype.h>
*/

#include "libft.h"

int	ft_isalpha(int i)
{
	if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
		return (1);
	return (0);
}
