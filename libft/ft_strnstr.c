/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:30:38 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/14 22:56:50 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!big && len == 0)
		return (NULL);
	if (big == little || little[j] == '\0')
		return ((char *)big);
	while (big[i])
	{
		if (big[i + j] == little[j] && big[i + j] && i + j < len)
			j++;
		else
		{
			i++;
			j = 0;
		}
		if (little[j] == '\0')
			return ((char *)big + i);
	}
	return (NULL);
}
