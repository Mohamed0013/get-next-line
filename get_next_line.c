/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohdahma <mohdahma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 10:34:01 by mohdahma          #+#    #+#             */
/*   Updated: 2024/12/14 10:34:01 by mohdahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_free_all(char *data_stored, char *buffer)
{
	if (data_stored)
		free(data_stored);
	if (buffer)
		free(buffer);
	return (NULL);
}

static char	*ft_extract_line(char *data_stored)
{
	int		i;
	char	*line;

	if (!*data_stored)
		return (NULL);
	i = 0;
	while (data_stored[i] && data_stored[i] != '\n')
		i++;
	if (!data_stored[i])
		i -= 1;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (data_stored[i] && data_stored[i] != '\n')
	{
		line[i] = data_stored[i];
		i++;
	}
	if (data_stored[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*ft_getleftover(char *data_stored)
{
	size_t	i;
	char	*buffer;

	i = 0;
	while (data_stored[i] && data_stored[i] != '\n')
		i++;
	if (!data_stored[i])
	{
		free(data_stored);
		return (NULL);
	}
	buffer = ft_strdup(data_stored + i + 1);
	if (!buffer)
		return (NULL);
	free(data_stored);
	return (buffer);
}

static char	*ft_read_it(int fd, char *data_stored)
{
	char	*buffer;
	char	*data_joined;
	ssize_t	bytes_read;

	buffer = malloc((BUFFER_SIZE * sizeof(char)) + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(data_stored, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		data_joined = ft_strjoin(data_stored, buffer);
		if (!data_joined)
			return (ft_free_all(data_stored, buffer));
		free(data_stored);
		data_stored = data_joined;
	}
	free(buffer);
	return (data_stored);
}

char	*get_next_line(int fd)
{
	static char	*data_stored;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	data_stored = ft_read_it(fd, data_stored);
	if (!data_stored)
		return (NULL);
	line = ft_extract_line(data_stored);
	if (!line)
		return (ft_free_all(data_stored, NULL));
	data_stored = ft_getleftover(data_stored);
	return (line);
}
