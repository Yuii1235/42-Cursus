/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:43:41 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/14 22:56:46 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *str1, char const *str2)
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
	return (new_str);
}
