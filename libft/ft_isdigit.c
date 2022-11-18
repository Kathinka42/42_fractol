/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:59:24 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 09:31:50 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_ISDIGIT
*	-----------
*	DESCRIPTION
*	The isdigit() function tests for a decimal digit character. ASCII '0' = 48,
*	'9' = 57; The return value is either 1 (true) or 0 (false).
*/

#include "libft.h"

int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	return (0);
}
