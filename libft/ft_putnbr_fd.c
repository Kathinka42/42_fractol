/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:57:32 by kczichow          #+#    #+#             */
/*   Updated: 2022/05/04 10:35:11 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_PUTNBR_FD
*	-------------
*	DESCRIPTION
*	The function converts the integer input to a character string and
*	outputs the string to the given file descriptor fd. To do this the function
*	calls itself (recursion), while dividing the input number by 10 each time
*	it does this. When the input number only contains one digit, the modulo
*	operation is used to print the individual chars with the putchar function.
*	The edge case -2147483648 is handled separately.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	res;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	res = n % 10 + '0';
	ft_putchar_fd(res, fd);
}
