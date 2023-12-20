/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:54:08 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/14 22:56:35 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char		*to;
	const char	*from;

	to = dst;
	from = src;
	if (to == NULL && from == NULL && n != 0)
		return (to);
	if (to < from)
		ft_memcpy(to, from, n);
	else
	{
		while (n > 0)
		{
			to[n - 1] = from[n - 1];
			n--;
		}
	}
	return (to);
}
