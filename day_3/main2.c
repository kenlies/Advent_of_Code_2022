#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char ftt_strchr(char *s, char c)
{
	int	i;

	if (!s)
		return ('\0');
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return c;
		i++;
	}
	if (s[i] == c)
		return c;
	return ('\0');
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

int addscore(int total_score, char c)
{
	int score;

	score = 0;
	if (c >= 97 && c <= 122)
	{
		score = c - 96;
		total_score += score;
	}
	else if (c >= 65 && c <= 90)
	{
		score = c - 38;
		total_score += score;
	}
	return total_score;
}

void	sortstrings(char **line1, char **line2, char **line3)
{	
	char *tmp;
	if (strlen(*line2) > strlen(*line1))
	{
		tmp = *line1;
		*line1 = *line2;
		*line2 = tmp;
	}
	if (strlen(*line3) > strlen(*line2))
	{
		tmp = *line2;
		*line2 = *line3;
		*line3 = tmp;
	}
	if (strlen(*line2) > strlen(*line1))
	{
		tmp = *line1;
		*line1 = *line2;
		*line2 = tmp;
	}
}

int	main(void)
{
	char	*line;
	char	*line1;
	char	*line2;
	char	*line3;
	int		i;
	int		j;
	int		fd1;
	int		total_score;
	char	c;
	int		flag;

	int	switch1 = 1;
	int	switch2 = 1;
	int	switch3 = 1;

	total_score = 0;
	fd1 = open("input.txt", O_RDONLY);
	while ((line = get_next_line(fd1)))
	{	
		if (switch1)
		{
			line1 = line;
			switch1 = 0;
		}
		else if (switch2)
		{
			line2 = line;
			switch2 = 0;
		}
		else if (switch3)
		{
			line3 = line;
			switch3 = 0;
		}
		if (!switch1 && !switch2 && !switch3)
		{
			sortstrings(&line1, &line2, &line3);
			i = 0;
			flag = 1;
			while (line1[i] != '\0')
			{
				c = ftt_strchr(line1, line2[i]);
				if (c != '\0')
				{
					j = 0;
					while (line3[j] != '\0')
					{
						if (ftt_strchr(line3, c) == c)
						{
							total_score = addscore(total_score, c);
							flag = 0;
							break ;
						}
						j++;
					}
					if (!flag)
						break ; 		 
				}
				i++;
			}
			switch1 = 1;
			switch2 = 1;
			switch3 = 1;
		}

	}
	printf("%i\n", total_score);
	close(fd1);
}