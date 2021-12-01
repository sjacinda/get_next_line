/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:05:50 by sjacinda          #+#    #+#             */
/*   Updated: 2021/12/02 01:00:52 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *line, char **tail)
{
	char	buf[BUFFER_SIZE + 1];
	char	*pn;
	int		count_read;

	while (!ft_strchr(line, '\n'))
	{
		count_read = read(fd, buf, BUFFER_SIZE);
		buf[count_read] = '\0';
		pn = ft_strchr(buf, '\n');
		if (pn)
		{
			*tail = ft_strdup(pn + 1);
			*(pn + 1) = '\0';
		}
		line = ft_strjoin(line, buf);
	}
	return (line);
}

char	*ft_end(char **tail)
{
	char	*line;
	char	*pn;
	char	*tmp_tail;

	pn = ft_strchr(*tail, '\n');
	if (pn)
	{
		tmp_tail = ft_strdup(pn + 1);
		*(pn + 1) = '\0';
		line = ft_strdup(*tail);
		free(*tail);
		*tail = tmp_tail;
	}
	else
	{
		line = *tail;
		*tail = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tail;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!tail)
		line = ft_strdup("");
	else
		line = ft_end(&tail);
	line = ft_read(fd, line, &tail);
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
