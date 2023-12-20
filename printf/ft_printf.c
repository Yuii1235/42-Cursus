/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:38:00 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/23 23:12:12 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_ptr(int *count, va_list list_arg)
{
	unsigned long	adr;

	adr = va_arg(list_arg, unsigned long);
	if (adr != 0)
		(*count) += write(1, "0x", 2);
	ft_put_ulb(adr, "0123456789abcdef", count);
}

void	ft_flag(int *count, int *i, char *s, va_list list_arg)
{
	if (s[(*i) + 1] == '%')
		(*count) += ft_put_c('%');
	else if (s[(*i) + 1] == 'c')
		(*count) += ft_put_c(va_arg(list_arg, int));
	else if (s[(*i) + 1] == 's')
		(*count) += ft_put_s(va_arg(list_arg, char *));
	else if (s[(*i) + 1] == 'd' || s[(*i) + 1] == 'i')
		ft_put_i(va_arg(list_arg, int), count);
	else if (s[(*i) + 1] == 'u')
		ft_put_uib(va_arg(list_arg, unsigned int), "0123456789", count);
	else if (s[(*i) + 1] == 'x')
		ft_put_uib(va_arg(list_arg, unsigned int), "0123456789abcdef", count);
	else if (s[(*i) + 1] == 'X')
		ft_put_uib(va_arg(list_arg, unsigned int), "0123456789ABCDEF", count);
	else if (s[(*i) + 1] == 'p')
		ft_ptr(count, list_arg);
	else
		(*count) += write(1, &s[(*i)], 2);
	(*i) += 2;
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	list_arg;

	i = 0;
	count = 0;
	va_start(list_arg, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
			ft_flag(&count, &i, (char *)s, list_arg);
		else if (s[i] == '%' && s[i + 1] == 0)
			return (-1);
		else
		{
			count += write(1, &s[i], 1);
			i++;
		}
	}
	va_end(list_arg);
	return (count);
}
