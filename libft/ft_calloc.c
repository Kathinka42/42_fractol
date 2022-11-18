/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:55:08 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/05 09:10:25 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_CALLOC
*	-----------
*	DESCRIPTION
*	The function allocates memory like malloc, but deletes everything that
*	might already be written in there. It uses bzero to do this.
*/

#include "libft.h"

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*ptr;

	if (size != 0 && 18446744073709551615UL / size < count)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
