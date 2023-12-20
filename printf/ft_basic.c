/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:01:54 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/23 22:37:20 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_put_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_s(char *s)
{
	int	size;

	if (!s)
		return (write(1, "(null)", 6));
	size = ft_strlen(s);
	write(1, s, size);
	return (size);
}
