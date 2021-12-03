/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:05:50 by sjacinda          #+#    #+#             */
/*   Updated: 2021/12/03 18:44:41 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_tail(char	*tail)
{
	int		i;
	char	*str;

	i = 0;
	while (tail[i] != '\n' && tail[i])
		i++;
	str = ft_substr(tail, i + 1, ft_strlen(tail));
	free(tail);
	return (str);
}

char	*ft_line(char	*tail)
{
	int		i;
	char	*line;

	i = 0;
	while (tail[i] != '\n' && tail[i])
		i++;
	line = ft_substr(tail, 0, i + 1);
	return (line);
}

char	*ft_read(int fd, char *tail)
{
	char	buf[BUFFER_SIZE + 1];
	int		count_read;

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
	static char	*tail;
	char		*line;

	if ((read(fd, 0, 0) < 0))
		return (NULL);
	tail = ft_read(fd, tail);
	if (!tail[0])
	{
		free(tail);
		tail = NULL;
		return (NULL);
	}
	line = ft_line(tail);
	tail = ft_tail(tail);
	return (line);
}

// int	main(void)
// {
// 	char	*s;
// 	int		fd;
// 	int		count_line;

// 	count_line = 23;
// 	fd = open("text.txt", O_RDONLY);
// 	while (count_line > 0)
// 	{
// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		free(s);
// 		count_line--;
// 	}
// 	close(fd);
// 	return (0);
// }