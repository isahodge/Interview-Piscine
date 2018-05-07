#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void	new_node(struct s_node **list, char c)
{
	struct s_node *new;
	struct s_node *tmp;

	new = (struct s_node*)malloc(sizeof(struct s_node));
	new->c = c;
	new->next = NULL;
	if (!(*list))
	{
		new->prev = NULL;
		(*list) = new;
	}
	else
	{
		tmp = (*list);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void	link_circle(struct s_node **list)
{
	struct s_node *tmp = (*list);
	while (tmp->next)
		tmp = tmp->next;
	(*list)->prev = tmp;
	tmp->next = (*list);

}

void	decode(int shift, struct s_node **list, char *str, int i)
{
	while (shift > 0)
	{
		(*list) = (*list)->next;
		shift--;
	}
	while (shift < 0)
	{
		(*list) = (*list)->prev;
		shift++;
	}
	str[i] = (*list)->c;
}

char	*precious(int *text, int size)
{
	char	*str;
	int		i;
	struct s_node *list;

	str = (char*)malloc(size + 1);
	list = NULL;
	i = 0;
	while (CS[i])
	{
		new_node(&list, CS[i]);
		i++;
	}
	link_circle(&list);
	/*while (list)//making sure double linked list works
	{
		printf("%c\n", list->c);
		list = list->prev;
	}*/
	i = 0;
	while (i < size)
	{
		decode(text[i], &list, str, i);
		i++;
	}
	return (str);
}
