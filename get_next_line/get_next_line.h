/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez-a <llopez-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:37:09 by llopez-a          #+#    #+#             */
/*   Updated: 2022/03/14 17:21:07 by llopez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strchr(const char *str, char c);
char	*ft_join(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*new_leftover(char *leftover);
char	*read_text(int fd, char *leftover);
char	*take_line(char *leftover);

#endif
