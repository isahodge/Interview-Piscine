#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

struct s_stack *stackInit(void)
{
	struct s_stack *new;

	if (!(new = (struct s_stack*)malloc(sizeof(struct s_stack))))
		return (NULL);
	new->item = NULL;
	return (new);
}

int pop(struct s_stack *stack)
{
	struct s_item	*tmp;

	if (stack && stack->item)
	{
		tmp = stack->item;
		stack->item = stack->item->next;
		tmp->next = NULL;
		return (tmp->idx);
	}
	return (-1);
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *new;

	if (!(new = (struct s_item*)malloc(sizeof(struct s_item))))
		return ;
	new->idx = idx;
	new->next = NULL;
	if (stack && stack->item)
	{
		new->next = stack->item;
		stack->item = new;
	}
	else
		stack->item = new;
}

char *console(void)
{
	char 	*buf_ptr;
	size_t	bufsize;
	char	*line;
	struct s_stack *stack;
	int		idx;

	buf_ptr = 0;
	bufsize = 255;
	line = (char *)malloc(bufsize);
	bzero(line, bufsize);
	stack = stackInit();
	idx = 0;
	do
	{
		printf("?: ");
		getline(&buf_ptr, &bufsize, stdin);
		if (!strcmp("SEND\n", buf_ptr))
			break ;
		else if (!strcmp("UNDO\n", buf_ptr))
		{
			idx = pop(stack);
			bzero(line + idx, bufsize - idx);
			printf("%s\n", line);
		}
		else
		{
			push(stack, idx);
			strncat(line, buf_ptr, strlen(buf_ptr) - 1);
			idx += strlen(buf_ptr) - 1;
			printf("%s\n", line);
		}
	}
	while (strcmp("SEND\n", buf_ptr));
	return (line);
}
