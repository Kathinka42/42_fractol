/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:54:24 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 11:38:38 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_TOUPPER
*	-------------
*	DESCRIPTION
*	The function converts lower-case letter to upper-case letter if there is
*	any; else it returns the input parameter.
*	ASCII: 'a' = 97, 'z' = 122;
*/

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
