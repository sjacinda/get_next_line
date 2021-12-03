/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:38:47 by sjacinda          #+#    #+#             */
/*   Updated: 2021/12/04 01:56:01 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1	// здесь можно задавать BUFFER_SIZE разного размера
# endif

// # ifndef BUFFER_SIZE	// таким образом можно переопределить BUFFER_SIZE,
// #  define BUFFER_SIZE 1	// если подаётся BUFFER_SIZE < 1
// # elif BUFFER_SIZE < 1
// #  undef BUFFER_SIZE
// #  define BUFFER_SIZE 1
// # endif

# include <stdio.h>	// для функции main, перед проверкой нужно удалить
# include <fcntl.h>	// для функции open
# include <stdlib.h>	// для функции malloc
# include <unistd.h>	// для остальных функций

char	*get_next_line(int fd);
char	*ft_read(int fd, char *tail);	// считывает файл и копирует в tail
char	*ft_line(char *tail);	// копирует готовую строку в line
char	*ft_tail(char *tail);	// сохраняет новый остаток для следующего вызова GNL

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int n);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif
