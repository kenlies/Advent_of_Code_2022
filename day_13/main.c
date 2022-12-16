#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int compare(char **left, char **right);

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
		char *a = line1 + 1;
		char *b = line2 + 1;
		i++;
		if (compare(&a, &b) > 0)
			total_score+= i;
		get_next_line(fd);
	}
	printf("%d", total_score);
	return 0;
}

// 0 = further evaluation, 1 = right order, -1, wrong order
int compare(char **left, char **right)
{
	char enlist[10] = {'['};
	char *e = enlist + 1;
	int x;
	int y;

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
			int i = 1;
			for (; *(*right) < 58 && *(*right) > 47; (*right)++)
				enlist[i++] = *(*right);
			enlist[i] = ']';
			(*left)++;
			x = compare(left, &e);
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
			int i = 1;
			for (; *(*left) < 58 && *(*left) > 47; (*left)++)
				enlist[i++] = *(*left);
			enlist[i] = ']';
			(*right)++;
			x = compare(&e, right);
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