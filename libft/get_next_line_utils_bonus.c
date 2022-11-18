/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:47:33 by kczichow          #+#    #+#             */
/*   Updated: 2022/11/10 13:10:51 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	FT_STRLEN_M
*	-------------
*	DESCRIPTION
*	Modified function from libft:
*	- added condition to take empty string
*	The strlen() function computes the length of the string s.  The strnlen()
*	function attempts to compute the length of s, but never scans beyond the
*	first maxlen bytes of s.
*/

size_t	ft_strlen_m(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/*	FT_STRCHR_M
*	-------------
*	DESCRIPTION
*	Modified function from libft:
*	- takes "char" as input instead of "const char"
*	- added condition to take empty string
*	The function locates the first occurence of c in string str, whereas the
*	terminating null is considered part of the string. Int i is converted to
*	char. The functions strchr() and strrchr() return a pointer to the located
*	character, or NULL if the character does not appear in the string.
*/

char	*ft_strchr_m(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	if (c == 0)
		return ((char *)str + ft_strlen_m(str));
	while (str[i] != '\0')
	{
		if ((char)c == str[i])
		{
			return ((char *) &str[i]);
		}
		i++;
	}
	return (NULL);
}

/*	FT_MEMCPY_M
*	-----------
*	DESCRIPTION
*	Modified function from libft: removed check for empty strings.
*	The function function copies n bytes from memory area src to memory area
*	dst.
*/

void	*ft_memcpy_m(void *dst1, const void *src1, size_t n)
{
	unsigned char		*dst;
	unsigned const char	*src;
	size_t				i;

	i = 0;
	dst = (unsigned char *)dst1;
	src = (unsigned const char *) src1;
	while (i < n)
	{
		dst[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst1);
}

/*	FT_STRJOIN_M
*	-------------
*	DESCRIPTION
*	Modified function from libft:
*	- takes "char" as input instead of "const char"
*	- added condition for empty string s1; this is needed when get_next_line
*	is called for the first time, because the statis variable remainder is
*	empty at this moment.
*	The function allocates (with malloc(3)) and returns a new string, which is
*	the result of the concatenation of ’s1’ and ’s2’.
*/

char	*ft_strjoin_m(char *s1, char *s2)
{
	char	*newstring;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen_m(s1);
	len_s2 = ft_strlen_m(s2);
	newstring = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (newstring == NULL)
		return (NULL);
	if (s1)
		ft_memcpy_m(newstring, s1, len_s1);
	ft_memcpy_m((newstring + len_s1), s2, len_s2);
	newstring[len_s1 + len_s2] = '\0';
	return (newstring);
}
