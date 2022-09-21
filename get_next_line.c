/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:44:35 by coder             #+#    #+#             */
/*   Updated: 2022/09/20 15:45:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*set_buffer(int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = set_buffer(fd, buffer);
	return (buffer);
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
	}
	free(tmp);
	return (buffer);
}
