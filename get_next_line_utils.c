/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: munshid <munshid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 00:10:41 by munshid           #+#    #+#             */
/*   Updated: 2025/12/20 12:12:22 by munshid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  len;

    len = 0;
    if (!str)
        return(0);
    while(str[len])
        len++;
    return (len);
}

void    *ft_calloc(size_t n, size_t size)
{
    char    *ptr;
    size_t  index;
    size_t  total_size;

    if (n !=0 && size > SIZE_MAX / n)
        return(malloc(0));
    total_size = size * n;
    ptr = (char *)malloc(total_size);
    if (!ptr)
        return((void *)NULL);
    index = 0;
    while(index < total_size)
        ptr[index++] = 0 ;
    return((void *)ptr);
}

int ft_memmove(char *mem1, char *mem2)
{
    size_t  index;

    index = 0;
    if (!mem2 || !mem1)
        return (0);
    while(mem2[index])
    {
        mem1[index] = mem2[index];
        index++;
    }
    mem1[index] = 0;
    return(1);
}

char    *ft_line(char *buffer)
{
    size_t  size;
    size_t  index;
    char    *rtn;

    index = 0;
    if (!buffer)
        return (NULL);
    while (buffer[index] && buffer[index] != '\n')
        index++;
    if (buffer[index] == '\n')
        index++;
    rtn = ft_calloc(index + 1, sizeof(char));
    if (!rtn)
        return (NULL);
    size = 0;
    while(size < index)
    {
        rtn[size] = buffer[size];
        size++;
    }
    return (rtn);
}

char    *ft_buff(char *buffer)
{
    size_t  index;
    char    *rtn;

    if (!buffer)
        return (NULL);
    index = 0;
    while(buffer[index] && buffer[index] != '\n')
        index++;
    if (!buffer[index] || !buffer[index+1])
    {
        free(buffer);
        return(NULL);
    }
    rtn = ft_calloc((ft_strlen(&buffer[index + 1])) + 1, sizeof(char));
    if (!rtn)
    {
        free(buffer);
        return(NULL);
    }
    ft_memmove(rtn, &buffer[index + 1]);
    free(buffer); 
    return (rtn);
}





