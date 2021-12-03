/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:05:50 by sjacinda          #+#    #+#             */
/*   Updated: 2021/12/03 02:19:16 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_before(char	*line)
{
	int		i;
	char	*s1;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	s1 = ft_substr(line, 0, i);
	if (!s1 || s1[0] == '\0')
		return (NULL);
	return (s1);
}

char	*ft_after(char	*line)
{
	int		i;
	char	*s2;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	s2 = ft_substr(line, i, ft_strlen(line));
	free(line);
	return (s2);
}

char	*ft_read(int fd, char *line)
{
	char	buf[BUFFER_SIZE + 1];
	int		n;

	n = 1;
	while (n > 0 && !ft_strchr(line, '\n'))
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (NULL);
		buf[n] = '\0';
		if (!line)
			line = ft_substr(buf, 0, n);
		else
			line = ft_strjoin(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*s;

	if ((read(fd, 0, 0) < 0))
		return (NULL);
	line = ft_read(fd, line);
	if (!line[0])
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	s = ft_before(line);
	line = ft_after(line);
	return (s);
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
