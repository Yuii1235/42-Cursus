/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:37:18 by eplouzen          #+#    #+#             */
/*   Updated: 2023/12/13 00:49:05 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	if ((long long)nmemb < 0 || (long long)size < 0 \
	|| size * nmemb > __SIZE_MAX__)
		return (NULL);
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, size * nmemb);
	return (array);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str1 && str2))
		return (NULL);
	new_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (new_str == NULL)
		return (NULL);
	while (str1[i])
	{
		new_str[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		new_str[j + i] = str2[j];
		j++;
	}
	new_str[j + i] = '\0';
	free(str1);
	return (new_str);
}
