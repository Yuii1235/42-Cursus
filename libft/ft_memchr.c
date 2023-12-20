/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 18:14:47 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/14 22:56:32 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s;

	i = 0;
	s = str;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (*(s + i) == (unsigned char )c)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (0);
}
