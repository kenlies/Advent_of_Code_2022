#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int compare_numbers(int num1, int num2, int num3, int num4)
{
	if (num1 >= num3 && num1 <= num4)
		return (1);
	else if (num3 >= num1 && num3 <= num2)
		return (1);
	return (0);
}

int	main(void)
{
	char	*line;
	int		fd1;
	int		total_score;
	int 	i;
	int		num1;
	int		num2;
	int		num3;
	int		num4;

	total_score = 0;
	fd1 = open("input.txt", O_RDONLY);
	while ((line = get_next_line(fd1)))
	{	
		i = 0;
		num1 = 0;
		num2 = 0;
		num3 = 0;
		num4 = 0;
		while (ft_isdigit(line[i]))
		{
			num1 = num1 * 10 + line[i] - '0';
			i++;
		}
		i++;
		while (ft_isdigit(line[i]))
		{
			num2 = num2 * 10 + line[i] - '0';
			i++;
		}
		i++;
		while (ft_isdigit(line[i]))
		{
			num3 = num3 * 10 + line[i] - '0';
			i++;
		}
		i++;
		while (ft_isdigit(line[i]))
		{
			num4 = num4 * 10 + line[i] - '0';
			i++;
		}
		total_score += compare_numbers(num1, num2, num3, num4);
	}
	printf("%i\n", total_score);
	close(fd1);
}