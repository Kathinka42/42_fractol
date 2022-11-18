/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:12:48 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 12:41:56 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_LSTNEW
 *	------------ 
 *	DESCRIPTION
 *	Like arrays, Linked List is a linear data structure. Unlike arrays, linked
 *	list elements are not stored at a contiguous location; the elements are
 *	linked using pointers.
 *	The new node is always added before the head of the given Linked List and
 *	becomes the new head of the Linked List. 
 *	The function allocates (with malloc(3)) and returns a new node. The member
 *	variable ’content’ is initialized with the value of the parameter ’content’.
 *	The variable ’next’ is initialized to NULL.
 */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	newnode->content = content;
	newnode->next = NULL;
	return (newnode);
}	
