/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:16:55 by sjacinda          #+#    #+#             */
/*   Updated: 2021/11/26 20:53:00 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


char	*ft_read(int fd, char *str, char *buf)
{
	int	len;

	len = 1;
	while (!ft_strchar(str, '\n' && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len < 0)
		{
			free(buf);
			return (0);
		}
		buf[len] = '\0';
		if (!str)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd);
{
	char		*buf;
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = ft_read(fd, str, buf);
	if (!str)
		return (NULL);
	
}