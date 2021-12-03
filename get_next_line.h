/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:38:47 by sjacinda          #+#    #+#             */
/*   Updated: 2021/12/03 18:44:53 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE 100

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *tail);
char	*ft_line(char	*tail);
char	*ft_tail(char	*tail);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

// # endif
#endif
