/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchow-so <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:23:49 by tchow-so          #+#    #+#             */
/*   Updated: 2024/03/29 15:16:07 by tchow-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This project is about programming a function that returns a line read
from a file descriptor. */

#include "get_next_line.h"

char	*read_from_fd(char *str, int fd);
char	*ft_get_line(char *str);
char	*clear_line(char *str);

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}
	str = read_from_fd(str, fd);
	if (!str)
		return (NULL);
	line = ft_get_line(str);
	str = clear_line(str);
	return (line);
}

/* read BUFFER_SIZE bytes from file (identified by fd) */
char	*read_from_fd(char *str, int fd)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_gnl(str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str = ft_strjoin_gnl(str, buffer);
	}
	free(buffer);
	return (str);
}

/* get line from 'str' and terminate it */
char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		line = malloc(i + 1);
	else
		line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

/* clear previous line from 'str' */
char	*clear_line(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str[i] && (str[i] != '\n'))
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * (ft_strlen_gnl(str) - i + 1));
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}
