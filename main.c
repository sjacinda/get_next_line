#include "get_next_line.h"

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
