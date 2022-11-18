/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:06:18 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 09:29:57 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_ISASCII
*	-----------
*	DESCRIPTION
*	The isascii() function tests for an ASCII character, which is any character
*	between 0 and 127 (octal 0177) inclusive. The return value is either
*	1 (true) or 0 (false).
*/

#include "libft.h"

int	ft_isascii(int i)
{
	if (i >= 0 && i <= 127)
		return (1);
	return (0);
}
