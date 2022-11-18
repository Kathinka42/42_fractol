/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:16:19 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 09:45:35 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_ITOA
*	-----------
*	DESCRIPTION
*	The function allocates (with malloc(3)) and returns a string representing
*	the integer received as an argument. Negative numbers must be handled.
*	It starts with counting the length of the input integer (auxiliary function
*	count_intlen) and uses this information to allocate enough memory for the
*	string (as always including an extra byte for the terminating 0).
*	If the input is negative, the number is set to its positive equivalent to
*	conduct the following steps.
*	The string is filled from its last position, setting the '\0' first and
*	using modulo operation to calculate the numbers. If the input is negative,
*	a - sign is set at the first position.
*/

#include "libft.h"

static size_t	count_intlen(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		count++;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	intlen;
	long	nb;

	nb = n;
	intlen = count_intlen(n);
	if (n < 0)
		nb = -nb;
	res = malloc(sizeof(char) * (intlen + 1));
	if (res == NULL)
		return (NULL);
	res[intlen] = '\0';
	while (intlen--)
	{
		res[intlen] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
