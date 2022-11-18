/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kczichow <kczichow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 09:06:32 by kczichowsky       #+#    #+#             */
/*   Updated: 2022/05/04 11:03:31 by kczichow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	FT_SPLIT
*	-------------
*	DESCRIPTION
*	This function is the most difficult function in the libft project at 42.
*	It allocates (with malloc(3)) and returns an array of strings obtained by
*	splitting ’s’ using the character ’c’ as a delimiter. The array must end
*	with a NULL pointer. In practical terms, the delimiter 'c' is most
*	likely a space sign, which separates different words.
*
*	AUXILIARY FUNCTIONS
*	-------------------
*	COUNT_WORD
*	-----------
*	DESCRIPTION
*	This function counts the number of words in the string. It considers the
*	possibility of various subsequent delimiters 'c' (spaces) and counts on
*	until it finds the next word. The return value (int) of this function is
*	used to allocate memory for the result array. It is also used to determine
*	the number of iterations that the print_word function writes in the result
*	array.
*
*	PRINT_WORD
*	-----------
*	DESCRIPTION
*	This function writes the word into the string array. It allocates memory
*	using the function ft_substr. As input it takes the position of the next
*	word to be copied in the string array. It iterates through the word, until
*	it either reaches the end of the string or the next delimiter.
*
*	CLEAN
*	------
*	DESCRIPTION
*	This function is called in every iteration of the loop where the words are
*	being copied into the string array. Only if the print_word function cannot
*	allocate enough memory for the next word (which is only know during
*	runtime of the function), it frees all previously allocated memory, because
*	the function cannot complete its task.
*/

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*print_word(char const *word, char c)
{
	size_t	len;
	char	*new_word;

	len = 0;
	while (word[len] != c && word[len] != '\0')
		len++;
	new_word = ft_substr(word, 0, len + 1);
	if (new_word != NULL)
		new_word[len] = '\0';
	return (new_word);
}

static void	clean(char **res, size_t j)
{
	size_t	count;

	count = 0;
	if (res[j] == NULL)
	{
		while (count < j)
		{
			free(res[count]);
			count++;
		}
	}	
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	res = ft_calloc(sizeof(char *), count_word(s, c) + 1);
	if (res == NULL)
		return (res);
	while (j < count_word(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		res[j] = print_word(s + i, c);
		clean (res, j);
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
	}
	res[j] = NULL;
	return (res);
}
