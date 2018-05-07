#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_stack *stackInit(void)
{
	struct s_stack *new;

	new = (struct s_stack*)malloc(sizeof(struct s_stack));
	new->item = NULL;
	return (new);
}

void *pop(struct s_stack *stack)
{
	struct s_item	*tmp;
	
	if (stack && stack->item)
	{
		tmp = stack->item;
		stack->item = stack->item->next;
		tmp->next = NULL;
		return (tmp->word);
	}
	return (NULL);
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *new;

	new = (struct s_item*)malloc(sizeof(struct s_item));
	new->word = word;
	new->next = NULL;
	if (stack && stack->item)
	{
		new->next = stack->item;
		stack->item = new;
	}
	else
		stack->item = new;
}

void printReverseV2(struct s_node *lst)
{
	struct s_item *tmp;
	struct s_stack *stack;

	stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	tmp = stack->item;
	while (tmp)
	{
		if (tmp->next)
			printf("%s ", tmp->word);
		else
			printf("%s\n", tmp->word);
		tmp = tmp->next;
	}
}
