/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:36:02 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/14 22:56:37 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t count)
{
	int	i;

	i = 0;
	while ((size_t)i < count)
	{
		((unsigned char *)ptr)[i] = (char)value;
		i++;
	}
	return (ptr);
}
