#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		current;
	int		total;

	current = 0;
	total = 0;
	i = 0;
	fd1 = open("input.txt", O_RDONLY);
	while ((line = get_next_line(fd1)))
	{	
		current += atoi(line);
		if (line[0] == '\n')
		{
			if (current > total)
				total = current;
			current = 0;
		}
	}
	printf("%i\n", total);
	close(fd1);
}