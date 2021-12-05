/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:05:50 by sjacinda          #+#    #+#             */
/*   Updated: 2021/12/05 12:21:46 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_tail(char *tail, int *j)
{
	char	*str;

	str = ft_substr(tail, *n + 1, ft_strlen(tail));
	free(tail);
	return (str);
}

char	*ft_line(char *tail, int *j)
{
	int		i;
	char	*line;

	i = 0;
	while (tail[i] != '\n' && tail[i])
		i++;
	line = ft_substr(tail, 0, i + 1);
	*n = i;	// присваиваю индекс по которому расположен '\n'
	return (line);
}

char	*ft_read(int fd, char *tail)
{
	int		count_read;
	char	buf[BUFFER_SIZE + 1];	// выделяется память на стеке

	count_read = 1;
	while (count_read > 0 && !ft_strchr(tail, '\n'))
	{
		count_read = read(fd, buf, BUFFER_SIZE);
		if (count_read < 0)
			return (NULL);
		buf[count_read] = '\0';
		if (!tail)
			tail = ft_substr(buf, 0, count_read);
		else
			tail = ft_strjoin(tail, buf);
	}
	return (tail);
}

char	*get_next_line(int fd)
{
	int			n;
	static char	*tail;	// остаток считанного после '\n', который нуже для слудующего вызова GNL
	char		*line;	// строка которая будет возращатся GNL

	if (fd < 0 || BUFFER_SIZE < 1 || (read(fd, 0, 0) < 0))	// важная защита для BUFFER_SIZE < 1
		return (NULL);
	tail = ft_read(fd, tail);
	if (!tail[0])
	{
		free(tail);
		tail = NULL;
		return (NULL);
	}
	n = 0;
	line = ft_line(tail, &j);	// отправляю n по адрусу, что бы работать с оригинальной переменной
	tail = ft_tail(tail, &j);	// здесь тоже
	return (line);
}

int	main(void)	// main для чтения из файла (fd >= 3)
{
	int		fd;
	int		count_line;
	char	*s;

	count_line = 23;
	fd = open("text.txt", O_RDONLY);
	while (count_line > 0)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
		count_line--;
	}
	close(fd);
	return (0);
}

int	main(void)	// main для чтения из стандартного ввода (fd == 0)
{
	char	*s;

	while ((s = get_next_line(0)))
	{
		printf("%s", s);
		free(s);
	}
	close(0);
	return (0);
}
