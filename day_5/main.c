#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}					t_list;

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

void	printlist(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		printf("%c - ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

void	moveNode(t_list **src, t_list **dest)
{
	t_list	*new;

	if (*src == NULL)
		return ;
	new = *src;
	*src = (*src)->next;
	new->next = *dest;
	*dest = new;
}

int	main(void)
{
	int		fd_1;
	int		i;
	char	*line;
	t_list	*head1;
	t_list	*head2;
	t_list	*head3;
	t_list	*head4;
	t_list	*head5;
	t_list	*head6;
	t_list	*head7;
	t_list	*head8;
	t_list	*head9;
	t_list	*array[9];
	int		count;
	int		loc1;
	int		loc2;

	head1 = NULL;
	head2 = NULL;
	head3 = NULL;
	head4 = NULL;
	head5 = NULL;
	head6 = NULL;
	head7 = NULL;
	head8 = NULL;
	head9 = NULL;
	ft_lstadd_front(&head1, ft_lstnew('C'));
	ft_lstadd_front(&head1, ft_lstnew('Z'));
	ft_lstadd_front(&head1, ft_lstnew('N'));
	ft_lstadd_front(&head1, ft_lstnew('B'));
	ft_lstadd_front(&head1, ft_lstnew('M'));
	ft_lstadd_front(&head1, ft_lstnew('W'));
	ft_lstadd_front(&head1, ft_lstnew('Q'));
	ft_lstadd_front(&head1, ft_lstnew('V'));
	ft_lstadd_front(&head2, ft_lstnew('H'));
	ft_lstadd_front(&head2, ft_lstnew('Z'));
	ft_lstadd_front(&head2, ft_lstnew('R'));
	ft_lstadd_front(&head2, ft_lstnew('W'));
	ft_lstadd_front(&head2, ft_lstnew('C'));
	ft_lstadd_front(&head2, ft_lstnew('B'));	//this is so re#$rded
	ft_lstadd_front(&head3, ft_lstnew('F'));
	ft_lstadd_front(&head3, ft_lstnew('Q'));
	ft_lstadd_front(&head3, ft_lstnew('R'));
	ft_lstadd_front(&head3, ft_lstnew('J'));
	ft_lstadd_front(&head4, ft_lstnew('Z'));
	ft_lstadd_front(&head4, ft_lstnew('S'));
	ft_lstadd_front(&head4, ft_lstnew('W'));
	ft_lstadd_front(&head4, ft_lstnew('H'));
	ft_lstadd_front(&head4, ft_lstnew('F'));
	ft_lstadd_front(&head4, ft_lstnew('N'));
	ft_lstadd_front(&head4, ft_lstnew('M'));
	ft_lstadd_front(&head4, ft_lstnew('T'));
	ft_lstadd_front(&head5, ft_lstnew('G'));
	ft_lstadd_front(&head5, ft_lstnew('F'));
	ft_lstadd_front(&head5, ft_lstnew('W'));
	ft_lstadd_front(&head5, ft_lstnew('L'));
	ft_lstadd_front(&head5, ft_lstnew('N'));
	ft_lstadd_front(&head5, ft_lstnew('Q'));
	ft_lstadd_front(&head5, ft_lstnew('P'));
	ft_lstadd_front(&head6, ft_lstnew('L'));
	ft_lstadd_front(&head6, ft_lstnew('P'));
	ft_lstadd_front(&head6, ft_lstnew('W'));
	ft_lstadd_front(&head7, ft_lstnew('V'));
	ft_lstadd_front(&head7, ft_lstnew('B'));
	ft_lstadd_front(&head7, ft_lstnew('D'));
	ft_lstadd_front(&head7, ft_lstnew('R'));
	ft_lstadd_front(&head7, ft_lstnew('G'));
	ft_lstadd_front(&head7, ft_lstnew('C'));
	ft_lstadd_front(&head7, ft_lstnew('Q'));
	ft_lstadd_front(&head7, ft_lstnew('J'));
	ft_lstadd_front(&head8, ft_lstnew('Z'));
	ft_lstadd_front(&head8, ft_lstnew('Q'));
	ft_lstadd_front(&head8, ft_lstnew('N'));
	ft_lstadd_front(&head8, ft_lstnew('B'));
	ft_lstadd_front(&head8, ft_lstnew('W'));
	ft_lstadd_front(&head9, ft_lstnew('H'));
	ft_lstadd_front(&head9, ft_lstnew('L'));
	ft_lstadd_front(&head9, ft_lstnew('F'));
	ft_lstadd_front(&head9, ft_lstnew('C'));
	ft_lstadd_front(&head9, ft_lstnew('G'));
	ft_lstadd_front(&head9, ft_lstnew('T'));	//but hey, it works c:
	ft_lstadd_front(&head9, ft_lstnew('J'));
	array[0] = &head1;
	array[1] = &head2;
	array[2] = &head3;
	array[3] = &head4;
	array[4] = &head5;
	array[5] = &head6;
	array[6] = &head7;
	array[7] = &head8;
	array[8] = &head9;
	fd_1 = open("input.txt", O_RDONLY);
	i = 0;
	while (i < 10)
	{
		get_next_line(fd_1);
		i++;
	}
	while (line = get_next_line(fd_1))
	{
		i = 0;
		count = 0;
		loc1 = 0;
		loc2 = 0;
		while (!ft_isdigit(line[i]))
			line[i++];
		while (ft_isdigit(line[i]))
		{
			count = count * 10 + line[i] - '0';
			i++;
		}
		while (!ft_isdigit(line[i]))
			line[i++];
		loc1 = line[i] - '0';
		i++;
		while (!ft_isdigit(line[i]))
			line[i++];
		loc2 = line[i] - '0';
		while (count > 0)
		{
			moveNode(array[loc1 - 1], array[loc2 - 1]);
			count--;
		}
	}
	printlist(head1);
	printlist(head2);
	printlist(head3);
	printlist(head4);
	printlist(head5);
	printlist(head6);
	printlist(head7);
	printlist(head8);
	printlist(head9);
}
