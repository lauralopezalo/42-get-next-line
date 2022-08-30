/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-a <llopez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:20:21 by llopez-a          #+#    #+#             */
/*   Updated: 2022/03/15 16:17:32 by llopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!leftover || !ft_strchr(leftover, '\n'))
		leftover = read_text(fd, leftover);
	if (!leftover)
		return (0);
	line = take_line(leftover);
	if (!line)
		return (0);
	leftover = new_leftover(leftover);
	return (line);
}

char	*read_text(int fd, char *leftover)
{
	ssize_t	readed;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	buffer[0] = '\0';
	readed = 1;
	while (readed > 0 && !ft_strchr(buffer, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed > 0)
		{
			buffer[readed] = '\0';
			leftover = ft_join(leftover, buffer);
		}
	}
	free (buffer);
	if (readed < 0)
	{
		free(leftover);
		return (0);
	}
	return (leftover);
}

char	*take_line(char *leftover)
{
	int		i;
	char	*line;

	i = 0;
	while (leftover[i] != '\0' && leftover[i] != '\n')
		i++;
	if (leftover[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	if (leftover[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	i = 0;
	while (leftover[i] != '\0' && leftover[i] != '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	if (leftover[i] == '\n')
	{
		line[i] = leftover[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*new_leftover(char *leftover)
{
	char	*legacy;
	int		i;
	int		j;

	i = 0;
	while (leftover[i] != '\0' && leftover[i] != '\n')
		i++;
	if (!leftover[i] || !leftover[i + 1])
	{
		free(leftover);
		return (0);
	}
	legacy = malloc((ft_strlen(leftover) - i) * sizeof(char));
	if (!legacy)
	{
		free(leftover);
		return (0);
	}
	i++;
	j = 0;
	while (leftover[i] != '\0')
		legacy[j++] = leftover[i++];
	legacy[j] = '\0';
	free(leftover);
	return (legacy);
}
