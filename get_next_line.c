/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: munshid <munshid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:48:52 by munshid           #+#    #+#             */
/*   Updated: 2025/12/22 15:09:09 by munshid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 
int ft_hasline(char *buffer,char c)
{
    if (!buffer)
        return (0);
    while(*buffer)
    {
        if (*buffer == c)
            break;
        buffer++;
    }
    if (*buffer == c)
        return (1);
    return (0);
}

char    *ft_strjoin(char *s1, char *s2)
{
    char    *rtn;
    size_t  s1_len;
    size_t  s2_len;
    // size_t  index;
    
    if (!s1 && !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    rtn = ft_calloc((s1_len + s2_len) + 1, sizeof(char));
    if (!rtn)
        return(NULL);
    // index = 0;
    ft_memmove(rtn, s1);
    ft_memmove(&rtn[s1_len], s2);
    free(s1);
    return(rtn);
}

char    *ft_filereader(int fd)
{
    char    temp[BUFFER_SIZE + 1];
    char    *rtn;
    ssize_t  byte_read;

    byte_read = 1;
    rtn = NULL;
    if (fd <0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    while( byte_read > 0)
    {
        byte_read = read(fd, temp, BUFFER_SIZE);
        if (byte_read == -1)
        {
            free(rtn);
            return (NULL);
        }
        if (byte_read == 0)
            return (NULL);
        temp[byte_read] = '\0';
        rtn = ft_strjoin(rtn, temp);
        if (!rtn)
            return (NULL);
        if (ft_hasline(rtn, '\n'))
            break;
    }
    return (rtn);
}

 char    *get_next_line(int fd)
{
    char    *temp;
    char    *line;
    char    *temp_buffer;
    static char *buffer[FOPEN_MAX];
    
    if (!buffer[fd])
        buffer[fd] = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 )
        return (NULL);

    temp = ft_filereader(fd);
    if (!temp && !buffer[fd])
        return (NULL);
    temp_buffer = temp;
    temp = ft_strjoin(buffer[fd], temp);
    free(temp_buffer);
    line = ft_line(temp);
    buffer[fd] = ft_buff(temp);
    return (line);
}