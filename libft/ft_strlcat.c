/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:33:36 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/14 22:56:47 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	length_dest;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	length_dest = ft_strlen(dst);
	if (length_dest > size)
		return (ft_strlen(src) + size);
	while (src[i] != '\0' && length_dest + i < size - 1)
	{
		dst[length_dest + i] = src[i];
		i++;
	}
	dst[length_dest + i] = '\0';
	return (length_dest + ft_strlen(src));
}
