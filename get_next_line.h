/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: munshid <munshid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:44:05 by munshid           #+#    #+#             */
/*   Updated: 2025/12/22 15:01:14 by munshid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <limits.h>


#define BUFFER_SIZE 10

char    *get_next_line(int fd);
size_t  ft_strlen(const char *str);
void    *ft_calloc(size_t n, size_t size);
int ft_memmove(char *mem1, char *mem2);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_line(char *buffer);
char    *ft_buff(char *buffer);
int ft_hasline(char *buffer,char c);
char    *ft_filereader(int fd);

#endif