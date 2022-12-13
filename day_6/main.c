#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}				t_list;
/*
void	printlist(t_list *head)
{
	t_list *tmp = head;
	while (tmp != NULL)
	{
		printf("%c - ", tmp->content);   //this was for testing
		tmp = tmp->next;
	}
	printf("\n");
}
*/
t_list	*ft_lstnew(char content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_front(t_list **head, t_list *new)
{
	if (!new)
		return ;
	if (!head)
	{
		*head = new;
		return ;
	}
	new->next = *head;
	*head = new;
}

void	ft_lstdel_back(t_list *head)
{
	t_list	*current;
	current = head;

	while (current->next->next != NULL)
		current = current->next;
	free(current->next);
	current->next = NULL;
}

int	is_in_list(t_list *head)
{
	while (head->next != NULL)
	{
		t_list *tmp = head->next;
		while (tmp != NULL)
		{
			if (head->content == tmp->content)
			{
				return 1;
			}
			tmp = tmp->next;
		}
		head = head->next;
	}
	return 0;
}

int	main(void)
{
	int		fd_1;
	int		count;
	int		total_count;
	int		i;
	char	*line;
	t_list	*head1;
	
	fd_1 = open("input.txt", O_RDONLY);
	i = 0;
	line = get_next_line(fd_1);
	head1 = NULL;
	total_count = 0;
	count = 0;
	while (line[i] != '\0')
	{
		ft_lstadd_front(&head1, ft_lstnew(line[i]));
		count += 1;
		if (count == 5)
		{
			if (!is_in_list(head1))
				break;
		}
		if (count > 4)
		{
			ft_lstdel_back(head1);
			count--;
		}
		total_count += 1;
		i++;
	}
	printf("%i\n", total_count);
	return 0;
}