/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:43:43 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/14 22:56:52 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_trimstart(char *s, char const *set)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_strchr(set, s[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_trimend(char *s, char const *set)
{
	int	len;

	len = ft_strlen(s);
	while (s[len - 1])
	{
		if (ft_strchr(set, s[len]) == 0)
			break ;
		len--;
	}
	return (len + 2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	char	*new_str;
	size_t	start;
	size_t	end;

	s = (char *)s1;
	if (!s)
		return (malloc(1));
	start = ft_trimstart(s, set);
	if (s[start] == '\0')
		return (ft_strdup(""));
	end = ft_trimend(s, set);
	new_str = malloc(sizeof(char) * (end - start));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s + start, end - start);
	return (new_str);
}
