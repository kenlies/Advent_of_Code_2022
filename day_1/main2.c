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
	int		total1;
	int		total2;
	int		total3;

	current = 0;
	total1 = 0;
	total2 = 0;
	total3 = 0;
	i = 0;
	fd1 = open("input.txt", O_RDONLY);
	while ((line = get_next_line(fd1)))
	{	
		current += atoi(line);
		if (line[0] == '\n')
		{
			if (current > total1)
				total1 = current;
			else if (current > total2)
				total2 = current;
			else if (current > total3)
				total3 = current;
			current = 0;
		}
	}
	printf("%i\n", total1 + total2 + total3);
	close(fd1);
}