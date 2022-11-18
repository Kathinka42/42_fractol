/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:02:26 by kczichow          #+#    #+#             */
/*   Updated: 2022/11/10 13:25:21 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_ATOI
*	-----------
*	DESCRIPTION
*	The function converts an ASCII string to an integer. It first checks for
*	leading whitespaces and sets the counter to the first character that is not
*	a whitespace. Secondly it checks for a + or - and sets the variable sign to
*	either a positive or negative value. It converts the character to integer by
*	subtracting '0'.
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
			sign = sign * (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
	number = number * 10 + str[i] - '0';
	i++;
	}
	return (number * sign);
}
