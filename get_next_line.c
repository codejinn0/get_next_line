/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aantari <aantari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:54:43 by aantari           #+#    #+#             */
/*   Updated: 2025/12/10 14:54:41 by aantari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_join(int fd, char *buffer, char *rest)
{
	ssize_t	bytes;
	char	*temp;

	while (!ft_strchr(rest, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes == -1)
			return (free(buffer), free(rest), NULL);
		buffer[bytes] = '\0';
		temp = ft_strjoin(rest, buffer);
		if (!temp)
			return (free(rest), free(buffer), NULL);
		free(rest);
		rest = temp;
	}
	free(buffer);
	return (rest);
}

static char	*return_line(char *rest)
{
	size_t	pos;
	char	*line;

	pos = 0;
	if (!rest)
		return (NULL);
	while (rest[pos] && rest[pos] != '\n')
		pos++;
	if (rest[pos] == '\n')
		line = ft_substr(rest, 0, pos + 1);
	else
		line = ft_strdup(rest);
	return (line);
}

static char	*update_rest(char *rest)
{
	size_t	pos;
	size_t	len;
	char	*newrest;

	if (!rest)
		return (NULL);
	pos = 0;
	while (rest[pos] && rest[pos] != '\n')
		pos++;
	len = ft_strlen(rest + pos + 1);
	newrest = ft_substr(rest, pos + 1, len);
	free(rest);
	rest = newrest;
	return (newrest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rest = read_and_join(fd, buffer, rest);
	if (!rest)
		return (NULL);
	line = return_line(rest);
	rest = update_rest(rest);
	if (!line || !line[0])
	{
		free(rest);
		free(line);
		rest = NULL;
		return (NULL);
	}
	return (line);
}
