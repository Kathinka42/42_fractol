/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 10:20:35 by kczichowsky       #+#    #+#             */
/*   Updated: 2022/05/04 12:38:45 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_LSTDELONE
 *	------------ 
 *	DESCRIPTION
 *	Takes as a parameter a node and frees the memory of the node’s content
 *	using the function ’del’ given as a parameter and free the node. The
 *	memory of ’next’ must not be freed.
 *	lst: The node to free.
 *	del: The address of the function used to delete the content.
 */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del == NULL)
		return ;
	if (lst != NULL)
	{
		(*del)(lst->content);
		free (lst);
	}	
}
