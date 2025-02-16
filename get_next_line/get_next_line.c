/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouanan <ybouanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 03:55:13 by kali              #+#    #+#             */
/*   Updated: 2025/02/16 22:36:36 by ybouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *store)
{
	char	*line;
	int		i;

	if (!store || !*store)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		if (store[i] == '\n')
			break ;
		line[i] = store[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*remaining_buffer(char *store)
{
	char	*remaining;
	int		i;
	int		j;

	if (!store)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
		return (free(store), NULL);
	remaining = malloc(ft_strlen(store) - i);
	if (!remaining)
		return (free(store), NULL);
	i++;
	j = 0;
	while (store[i])
		remaining[j++] = store[i++];
	remaining[j] = '\0';
	free(store);
	return (remaining);
}

char	*read_file(int fd, char *store)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(store), NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(store, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (free(store), NULL);
		}
		buffer[bytes_read] = '\0';
		store = ft_strjoin(store, buffer);
		if (!store)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (store);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_file(fd, store);
	if (!store)
		return (NULL);
	line = extract_line(store);
	if (!line)
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	store = remaining_buffer(store);
	return (line);
}
