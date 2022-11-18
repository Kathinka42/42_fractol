/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:55:08 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 09:18:51 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_BZERO
*	-----------
*	DESCRIPTION
*	The bzero() function writes len zeroed bytes to the string str. An empty
*	string is not being considered and leads to segfault.
*/

#include "libft.h"

void	*ft_bzero(void *str, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}
