/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:59:43 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 11:09:16 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_STRDUP
*	-------------
*	DESCRIPTION
*	The strdup()function allocates sufficient memory for a copy of the string
*	s, does the copy, and returns a pointer to it. The pointer may subsequently
*	be used as an argument to the function free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dupl;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	dupl = malloc(sizeof(char) * (len + 1));
	if (dupl == NULL)
		return (NULL);
	else
		i = 0;
	while (i < len && s1[i] != '\0')
	{
		dupl[i] = s1[i];
		i++;
	}
	dupl[i] = '\0';
	return (dupl);
}
