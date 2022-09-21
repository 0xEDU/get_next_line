/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:45:27 by coder             #+#    #+#             */
/*   Updated: 2022/09/20 15:37:06 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = 0;
	if (!size || !count)
		return (malloc(0));
	if (size > 2147483647 / count)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (p);
	while (i < size * count)
		p[i++] = '\0';
	return (p);
}

int	ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		else
			i++;
	}
	return (0);
}
