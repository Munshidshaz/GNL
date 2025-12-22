/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: munshid <munshid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:39:11 by munshid           #+#    #+#             */
/*   Updated: 2025/12/22 15:10:34 by munshid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
#include <assert.h>
#include <stdarg.h>

int	ft_free(int count, ...)
{
	va_list	pointers;
	void	*ptr;
	int index;

	index = 0;
	va_start(pointers, count);
	while (index < count)
	{
		ptr = va_arg(pointers, void*);
		free(ptr);
		index++;
	}
	va_end(pointers);
	return(1);
}

int main(void)
{
	int	fd;
	int fd2;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	printf("fd : %d, fd2 : %d\n", fd, fd2);
	char *str1;
	char *str2;
	char *str3;
	char *str4;

	str1 = get_next_line(fd);
	str2 = get_next_line(fd);
	str3 = get_next_line(fd);
	str4 = get_next_line(fd);

	ft_free(4,str1, str2, str3, str4);     

	free

	return (1);
}
