#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_node *cloneGameBoard(struct s_node *node)
{
	struct s_node *copy;
	struct s_node *tmp;
	struct s_node *head;

	head = node;
	while (node)
	{
		copy = (struct s_node *)malloc(sizeof(struct s_node));
		copy->value = node->value;
		copy->random = NULL;
		copy->next = node->next;
		node->next = copy;
		node = copy->next;
	}
	node = head;
	while (node && node->next)
	{
		if (node->random && node->next)
			node->next->random = node->random->next;
		if (node->next)
			node = node->next->next;
	}
	node = head;
	tmp = node->next;
	copy = tmp;
	while (node && tmp)
	{
		if (node->next)
			node->next = node->next->next;
		if (tmp->next)
			tmp->next = tmp->next->next;
		node = node->next;
		tmp = tmp->next;
	}
	return (copy);
}
