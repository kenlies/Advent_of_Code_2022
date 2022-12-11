#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		total_score;

	total_score = 0;
	fd1 = open("input.txt", O_RDONLY);
	while ((line = get_next_line(fd1)))
	{	
		if (line[0] == 'A')
		{
			if (line[2] == 'X')
				total_score += 3;
			else if (line[2] == 'Y')
				total_score += 1 + 3;
			else if (line[2] == 'Z')
				total_score += 2 + 6;
		}
		else if (line[0] == 'B') 
		{
			if (line[2] == 'X')
				total_score += 1;
			else if (line[2] == 'Y')
				total_score += 2 + 3;
			else if (line[2] == 'Z')
				total_score += 3 + 6;
		}
		else if (line[0] == 'C')
		{
			if (line[2] == 'X')
				total_score += 2;
			else if (line[2] == 'Y')
				total_score += 3 + 3;
			else if (line[2] == 'Z')
				total_score += 1 + 6;
		}
	}
	printf("%i", total_score);
	close(fd1);
}