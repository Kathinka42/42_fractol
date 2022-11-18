/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 08:52:18 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 09:24:00 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_ISALNUM
*	-----------
*	DESCRIPTION
*	The function tests for any character for which isalpha(3) or isdigit(3)
*	is true.  The value of the argument must be representable as an unsigned
*	char or the value of EOF. The return value is either 1 (true) or 0 (false).
*/

#include "libft.h"

int	ft_isalnum(int i)
{
	if (ft_isalpha(i) == 1 || ft_isdigit(i) == 1)
		return (1);
	return (0);
}
