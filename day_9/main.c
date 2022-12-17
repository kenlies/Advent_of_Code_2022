#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	in_touch(int y_head, int x_head, int y_tail, int x_tail)
{
	if (abs(y_head - y_tail) >= 2)
		return (0);
	if (abs(x_head - x_tail) >= 2)
		return (0);
	return (1);
}

int	main(void)
{
	int fd_1;
	char *line;
	int rows = 1000;
	int cols = 1000;
	char dir;
	int move_count;
	int score = 1;
	int y_head = 500;
	int x_head = 500;
	int y_tail = 500;
	int x_tail = 500;

	int *t_grid = (int *)malloc(rows * cols * sizeof(int));

	t_grid[y_tail * cols + x_tail] = 1;

	fd_1 = open("input.txt", O_RDONLY);

	while ((line = get_next_line(fd_1)))
	{
		dir = line[0];
		line++;
		move_count = atoi(line);

		int i = 0;
		while (i < move_count)
		{
			if (dir == 'R')
			{
				x_head++;
			}
			else if (dir == 'L')
			{
				x_head--;
			}
			else if (dir == 'U')
			{
				y_head--;
			}
			else
				y_head++;

			if (!in_touch(y_head, x_head, y_tail, x_tail))
			{
				if (dir == 'R')
				{
					x_tail = x_head - 1;
					y_tail = y_head;
				}
				else if (dir == 'L')
				{
					x_tail = x_head + 1;
					y_tail = y_head;
				}
				else if (dir == 'U')
				{
					y_tail = y_head + 1;
					x_tail = x_head;
				}
				else if (dir == 'D')
				{
					y_tail = y_head - 1;
					x_tail = x_head;
				}
				if (t_grid[y_tail * cols + x_tail] != 1)
				{
					t_grid[y_tail * cols + x_tail] = 1;
					score++;
				}
			}
			i++;
		}
	}
	printf("%d\n", score);
}