/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:05:50 by sjacinda          #+#    #+#             */
/*   Updated: 2021/12/03 01:33:47 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *line, char **tail)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;
	char	*pn;
	int		count_read;
	
	count_read = 1;
	while (count_read > 0 && !ft_strchr(line, '\n'))
	{
		count_read = read(fd, buff, BUFFER_SIZE);
		if (count_read < 1 && *line == '\0')
		{
			free(line);
			return (NULL);
		}
		buff[count_read] = '\0';
		pn = ft_strchr(buff, '\n');
		if (pn)
		{
			*tail = ft_strdup(pn + 1);
			*(pn + 1) = '\0';
		}
		tmp = line;
		line = ft_strjoin(line, buff);
		free(tmp);
	}
	return (line);
}

char	*ft_end(char **tail)
{
	char	*line;
	char	*pn;
	char	*tmp_tail;

	pn = ft_strchr(*tail, '\n');
	if (!pn)
	{
		line = *tail;
		*tail = NULL;
		return (line);
	}
	tmp_tail = ft_strdup(pn + 1);
	*(pn + 1) = '\0';
	line = ft_strdup(*tail);
	free(*tail);
	*tail = tmp_tail;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tail;
	char		*line;
	
	if ((read(fd, 0, 0) < 0))
		return (NULL);
	if (!tail)
		line = ft_strdup("");
	else
		line = ft_end(&tail);
	line = ft_read(fd, line, &tail);
	return (line);
}

// int	main(void)
// {
// 	char	*s;
// 	int		fd;
// 	int		count_line;

// 	count_line = 22;
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
