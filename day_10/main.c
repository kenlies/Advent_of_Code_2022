#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	char *line;
	int fd;
	int cycles;
	int x;
	int strength;
	int value;
	char inst;
	int i;

	fd = open("input.txt", O_RDONLY);
	cycles = 0;
	x = 1;
	i = 1;
	strength = 0;
	value = 0;
	while ((line = get_next_line(fd)))
	{
		inst = line[0];
		while (*line != ' ')
			line++;
		if (inst == 'a')
			value = atoi(line);
		if (inst == 'n')
			cycles++;
		else
		{
			cycles++;
			if (cycles == 20 || cycles == 60 || cycles == 100 || cycles == 140 || cycles == 180 || cycles == 220)
				strength += cycles * x;
			cycles++;
		}
		if (cycles == 20 || cycles == 60 || cycles == 100 || cycles == 140 || cycles == 180 || cycles == 220)
			strength += cycles * x;
		if (inst == 'a')
			x = x + value;
		i++;
	}
	printf("%d\n", strength);
	return 0;
}