/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:36:03 by kczichowsky       #+#    #+#             */
/*   Updated: 2022/05/04 13:03:39 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_LSTMAP
 *	------------ 
 *	DESCRIPTION
 *	Iterates the list ’lst’ and applies the function ’f’ on the content of
 *	each node. Creates a new list resulting of the successive applications of
 *	the function ’f’. The ’del’ function is used to delete the content of a
 *	node if needed.
 */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new_list;
	t_list	*new_element;

	temp = lst;
	new_list = NULL;
	while (temp)
	{
		new_element = ft_lstnew((*f)(temp->content));
		if (!new_element)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		temp = temp->next;
	}
	return (new_list);
}
