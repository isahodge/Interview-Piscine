#include "header.h"
#include <stdlib.h>

struct s_queue *queueInit(void)
{
	struct s_queue *new;

	if (!(new = (struct s_queue*)malloc(sizeof(struct s_queue))))
		return (NULL);
	new->first = NULL;
	new->last = NULL;
	return (new);
}

char *dequeue(struct s_queue *queue)
{
	struct s_node *tmp;
	
	tmp = NULL;
	if (queue)
		tmp = queue->first;
	if (tmp)
	{
		queue->first = queue->first->next;
		return (tmp->message);
	}
	return (NULL);
}

void enqueue(struct s_queue *queue, char *message)
{
	struct s_node *tmp;
	struct s_node *new;

	if (!(new = (struct s_node*)malloc(sizeof(struct s_node))))
		return ;
	new->message = message;
	new->next = NULL;
	tmp = NULL;
	if (queue && queue->last)
	{
		tmp = queue->last;
		tmp->next = new;
		queue->last = new;
	}
	else if (queue)
	{
		queue->first = new;
		queue->last = new;
	}
}

char *peek(struct s_queue *queue)
{
	if (queue && queue->first)
	{
		return (queue->first->message);
	}
	return (NULL);
}

int isEmpty(struct s_queue *queue)
{
	if (queue && queue->first)
	{
		return (0);
	}
	return (1);
}
