#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

// 0 = further evaluation, 1 = right order, -1, wrong order
int compare_line(char **left, char **right)
{
	char clist[10] = {'['};
	char *c = clist + 1;
	int x;
	int y;
	int i;

	while (1)
	{
		if (*(*left) == ',')
			(*left)++;
		if (*(*right) == ',')
			(*right)++;
		if ((*(*right) == ']') && (*(*left) != ']'))
			return -1;
		//////////////////////////////////////////////////////////
		if (*(*left) == '[')
		{
			if (*(*right) == '[')
			{
				(*left)++;
				(*right)++;
				x = compare(left, right);
				if (x)
					return x;
				continue;
			}
			i = 1;
			for (; *(*right) < 58 && *(*right) > 47; (*right)++)
				clist[i++] = *(*right);
			clist[i] = ']';
			(*left)++;
			x = compare(left, &c);
			if (x)
				return x;
			continue;
		}
		//////////////////////////////////////////////////////////
		if (*(*left) == ']')
		{
			if (*(*right) == ']')
			{
				(*left)++;
				(*right)++;
				return 0;
			}
			else
				return 1;
		}
		//////////////////////////////////////////////////////////
		if (*(*right) == '[')
		{
			i = 1;
			for (; *(*left) < 58 && *(*left) > 47; (*left)++)
				clist[i++] = *(*left);
			clist[i] = ']';
			(*right)++;
			x = compare(&c, right);
			if (x)
				return x;
			continue;
		}
		//////////////////////////////////////////////////////////
		x = atoi(*left);
		y = atoi(*right);
		if (x < y)
			return 1;
		if (x > y)
			return -1;
		for (; *(*left) < 58 && *(*left) > 47; (*left)++);
		for (; *(*right) < 58 && *(*right) > 47; (*right)++);
	}
}

int main ()
{
	char *line1;
	char *line2;
	int fd;
	int i;
	int total_score;

	if ((fd = open("input.txt", O_RDONLY)) == -1)
	{
		printf("Error opening the file!\n");
		return 1;
	}
	total_score = 0;
	i = 0;
	while ((line1 = get_next_line(fd)) && (line2 = get_next_line(fd)))
	{	
		line1 + 1;
		line2 + 1;
		i++;
		if (compare_line(&line1, &line2) > 0)
			total_score+= i;
		get_next_line(fd);
	}
	printf("%d", total_score);
	return 0;
}
