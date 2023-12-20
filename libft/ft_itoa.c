/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 20:44:05 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/14 22:56:31 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	size_n;

	size_n = 0;
	if (n < 0)
	{
		size_n = size_n + 1;
		n = -n;
	}
	while (n >= 10)
	{
		size_n++;
		n = n / 10;
	}
	if (n < 10)
	{
		size_n += 1;
	}
	return (size_n);
}

void	ft_swap(char *a, char *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_reverse(char *str)
{
	size_t	i;
	int		size_str;

	i = 0;
	size_str = ft_strlen(str) - 1;
	while (i < (ft_strlen(str) / 2))
	{
		ft_swap(&str[size_str], &str[i]);
		size_str--;
		i++;
	}
}

int	ft_sign(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -sign;
	return (sign);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb ;
	char	*buffer;

	i = 0;
	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb < 0)
		nb = -nb;
	buffer = ft_calloc((ft_intlen(n)) + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (nb)
	{
		buffer[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (ft_sign(n) < 0)
		buffer[i++] = '-';
	ft_reverse(buffer);
	buffer[i] = '\0';
	return (buffer);
}
