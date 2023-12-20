/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:38:11 by eplouzen          #+#    #+#             */
/*   Updated: 2023/11/24 22:42:43 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_strlen(char *str);
int		ft_put_c(char c);
int		ft_put_s(char *s);
void	ft_put_i(int n, int *count);
void	ft_put_uib(unsigned int nbr, char *base, int *count);
void	ft_put_ulb(unsigned long nbr, char *base, int *count);
int		ft_printf(const char *s, ...);

#endif
