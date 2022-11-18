/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichowsky <kczichowsky@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:21:33 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/03 14:30:38 by kczichowsky      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_LSTADD_FRONT
 *	------------ 
 *	DESCRIPTION
 *	The function adds the node ’new’ at the beginning of the list.
 *	The new node is always added before the head of the given Linked List and
 *	becomes the new head of the Linked List.
 *	lst: The address of a pointer to the first link of a list.
 *	new: The address of a pointer to the node to be added to the list.
 */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}
