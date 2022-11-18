/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:13:04 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 09:36:09 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_ISPRINT
*	-----------
*	DESCRIPTION
*	The function tests for any printing character, including space
*	(` '). The value of the argument must be representable as an unsigned char
*	or the value of EOF. The return value is either 1 (true) or 0 (false).
*/

#include "libft.h"

int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}
