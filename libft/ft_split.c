/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 21:03:58 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/14 22:56:43 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_strs(char const *s, char c)
{
	int	i;
	int	count_word;

	i = 0;
	count_word = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count_word++;
		i++;
	}
	return (count_word);
}

void	*free_tab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

void	*ft_copy_till_delimiter(char const *s, char c, char **array, int index)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	array[index] = ft_calloc(i + 1, sizeof(char));
	if (array[index] == NULL)
		return (free_tab(array));
	ft_strlcpy(array[index], (char *)s, i + 1);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		cursor;
	int		index;
	int		count_word;
	char	**array;

	if (!s)
		return (0);
	cursor = 0;
	index = 0;
	count_word = ft_count_strs(s, c);
	array = ft_calloc(count_word + 1, sizeof(char *));
	if (array == NULL)
		return (0);
	while (s[cursor] && (unsigned int) cursor < ft_strlen(s))
	{
		if (s[cursor] == c)
		{
			cursor++;
			continue ;
		}
		ft_copy_till_delimiter(s + cursor, c, array, index);
		cursor += ft_strlen(array[index]);
		index++;
	}
	return (array);
}
