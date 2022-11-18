/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 14:25:23 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 13:09:36 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_LSTSIZE
 *	------------ 
 *	DESCRIPTION
 *	Counts the number of nodes in a list, with lst: The beginning of the list.
 *	*lst contains the address of the head node and is therefore never
 *	modified; we always use a temp variable to traverse the list;
 */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*temp;

	count = 0;
	if (lst == NULL)
		return (0);
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
