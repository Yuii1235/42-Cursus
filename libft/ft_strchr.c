/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:26:32 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/14 22:56:44 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)string;
	while (str[i])
	{
		if (str[i] == (unsigned char)searchedChar)
			return (str + i);
		else
			i++;
	}
	if (str[i] == searchedChar)
		return (str + i);
	return (NULL);
}
