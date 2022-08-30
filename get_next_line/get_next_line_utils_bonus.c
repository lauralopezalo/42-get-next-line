/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-a <llopez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:21:16 by llopez-a          #+#    #+#             */
/*   Updated: 2022/03/15 17:30:35 by llopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strchr(const char *buffer, char c)
{
	int	i;

	if (!buffer || !c)
		return (0);
	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

char	*ft_join(char *leftover, char *buffer)
{
	char	*str;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!leftover)
	{
		leftover = (char *)malloc(sizeof(char));
		leftover[0] = '\0';
	}
	size = ft_strlen(leftover) + ft_strlen(buffer);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	i = -1;
	while (leftover[++i] != '\0')
		str[i] = leftover[i];
	j = -1;
	while (buffer[++j] != '\0')
		str[i + j] = buffer[j];
	str[i + j] = '\0';
	free (leftover);
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
