/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:44:35 by coder             #+#    #+#             */
/*   Updated: 2022/09/21 22:37:54 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*set_buffer(int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = set_buffer(fd, buf);
	return (buf);
}

static char	*set_buffer(int fd, char *buffer)
{
	char	*tmp;
	ssize_t	i;

	i = 0;
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (ft_strchr(buffer, '\n') != 1)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == 0 || i == -1)
			break ;
		tmp[i] = '\0';
		buffer = ft_strjoin(buffer, tmp);
		if (buffer == NULL)
		{
			free(tmp);
			return (NULL);
		}
	}
	free(tmp);
	return (buffer);
}
