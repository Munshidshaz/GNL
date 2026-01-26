/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: munshid <munshid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:48:52 by munshid           #+#    #+#             */
/*   Updated: 2026/01/23 15:19:20 by munshid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_hasline(char *buffer, char c)
{
	size_t	index;

	index = 0;
	if (!buffer[index])
		return (0);
	while (buffer[index] && buffer[index] != c)
		index++;
	if (buffer[index] == c)
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*rtn;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	rtn = ft_calloc((s1_len + s2_len) + 1, sizeof(char));
	if (!rtn)
		return (NULL);
	ft_memmove(rtn, s1);
	ft_memmove(&rtn[s1_len], s2);
	free (s1);
	return (rtn);
}

char	*ft_filereader(int fd, char *buffer)
{
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(temp);
			return(NULL);
		}
		temp[bytes_read] = 0;
		buffer = ft_strjoin(buffer, temp);
		if (ft_hasline(buffer, '\n'))
			break ;
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	buffer[fd] = ft_filereader(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_buff(buffer[fd]);
	return (line);
}
