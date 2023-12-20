/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eplouzen <eplouzen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 00:36:51 by eplouzen          #+#    #+#             */
/*   Updated: 2023/12/13 00:48:59 by eplouzen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_bool_n_cut(char *to_ret, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (to_ret[i] && to_ret[i] != '\n')
		i++;
	if (to_ret[i] == '\n')
	{
		i++;
		while (to_ret[i])
		{
			buffer[j] = to_ret[i];
			i++;
			j++;
		}
		buffer[j] = '\0';
		to_ret[i - j] = '\0';
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	int			check_read;
	char		*to_ret;
	static char	*buffer;

	to_ret = ft_calloc(1, 1);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (buffer && to_ret)
	{
		to_ret = ft_strjoin(to_ret, buffer);
		if (ft_bool_n_cut(to_ret, buffer))
			return (to_ret);
		check_read = read(fd, buffer, BUFFER_SIZE);
		if (check_read < 1)
		{
			free(buffer);
			buffer = NULL;
			if (to_ret[0] != '\0')
				return (to_ret);
			free(to_ret);
			return (NULL);
		}
		buffer[check_read] = '\0';
	}
	return (NULL);
}
