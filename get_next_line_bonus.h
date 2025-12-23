/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: munshid <munshid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:44:05 by munshid           #+#    #+#             */
/*   Updated: 2025/12/23 20:15:06 by mmohamm2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

size_t	ft_strlen(const char *str);
size_t	ft_memmove(char *mem1, char *mem2);
ssize_t	ft_hasline(char *buffer, char c);

char	*get_next_line(int fd);
void	*ft_calloc(size_t n, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_line(char *buffer);
char	*ft_buff(char *buffer);
char	*ft_filereader(int fd, char *buffer);

#endif
