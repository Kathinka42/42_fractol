/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:10:27 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 11:38:07 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_TOLOWER
*	-------------
*	DESCRIPTION
*	The function converts upper-case letter to lower-case letter if there is
*	any; else it returns the input parameter.
*	ASCII: 'A' = 65, 'Z' = 90.
*/

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
