#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main()
{
	char *line;
	int fd;
	int x;
	int value;
	char inst;
	int i;

	char *crt;

	crt = malloc(40);
	fd = open("input.txt", O_RDONLY);
	i = 0;
	x = 1;
	value = 0;
	memset(crt, '.', 40);
	crt[40] = '\0';
	while ((line = get_next_line(fd)))
	{
		if (i == 40 || i == 41)
		{
			memset(crt, '.', 40);
			crt[40] = '\0';
			if (i == 40)
				i = 0;
			else
				i = 1;
		}
		inst = line[0];
		while (*line != ' ')
			line++;
		if (inst == 'a')
			value = atoi(line);

		if (inst == 'n')
		{
			if (i == x || i == x - 1 || i == x + 1)
				crt[i] = '#';
			i++;
		}
		else
		{
			if (i == x || i == x - 1 || i == x + 1)
				crt[i] = '#';
			i++;
			if (i == x || i == x - 1 || i == x + 1)
				crt[i] = '#';
			i++;
			if (i == 41)
				printf("%s\n", crt);
		}
		if (inst == 'a')
			x = x + value;
		if (i == 40)
			printf("%s\n", crt);
	}
	return 0;
}
