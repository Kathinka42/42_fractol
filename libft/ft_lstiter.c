/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:52:16 by kczichowsky       #+#    #+#             */
/*   Updated: 2022/05/04 12:39:35 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_LSTITER
 *	------------ 
 *	DESCRIPTION
 *	The function iterates the list ’lst’ and applies the function
 *	’f’ on the content of each node.
 *	lst: The address of a pointer to a node.
 *	f: The address of the function used to iterate on the list.
 */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	if (temp == NULL || f == NULL)
		return ;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
