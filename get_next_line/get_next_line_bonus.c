/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-a <llopez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:17:53 by llopez-a          #+#    #+#             */
/*   Updated: 2022/03/15 16:21:24 by llopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*leftover[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 256)
		return (0);
	if (!leftover[fd] || !ft_strchr(leftover[fd], '\n'))
		leftover[fd] = read_text(fd, leftover[fd]);
	if (!leftover[fd])
		return (0);
	line = take_line(leftover[fd]);
	if (!line)
		return (0);
	leftover[fd] = new_leftover(leftover[fd]);
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
		line = malloc(sizeof(char) * (ft_strlen(leftover) + 1));
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
