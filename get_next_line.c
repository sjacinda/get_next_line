/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacinda <sjacinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:37:45 by sjacinda          #+#    #+#             */
/*   Updated: 2021/11/12 15:15:48 by sjacinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

char *plus(int fd)
{
	static char	a[5];

	read(fd, a, 4);
	a[4] = '\0';
	return(a);
}

int	main(void)
{
	int	fd;

	fd = open("../test.txt", O_RDONLY);
	printf("%s\n", plus(fd));
	close(fd);
	return (0);
}
