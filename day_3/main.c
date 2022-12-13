#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

char ftt_strchr(const char *s, char c)
{
	int	i;

	if (!s)
		return ('\0');
	i = 0;
	while (s[i])
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

int	main(void)
{
	char	*line;
	char	*line2;
	char	c;
	int		i;
	int		fd1;
	int		total_score;
	int		score;

	score = 0;
	total_score = 0;
	fd1 = open("input.txt", O_RDONLY);
	while ((line = get_next_line(fd1)))
	{	
		line2 = ft_substr(line, strlen(line) / 2, strlen(line));
		line = ft_substr(line, 0, strlen(line) / 2);
		i = 0;
		c = '\0';
		while (line2[i] != '\0')
		{
			c = ftt_strchr(line, line2[i]);
			if (c != '\0')
			{
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
				score = 0;
				break ; 	 
			}
			i++;
		}

	}
	printf("%i\n", total_score);
	close(fd1);
}