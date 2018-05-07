#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

int main(void)
{
	struct s_queue	*q;
	struct s_node	*tmp;
	/*-------------------
	launch your test here
	--------------------*/
	q = queueInit();
	printf("Empty? %i\n", isEmpty(q));
	enqueue(q, "hello");
	printf("Empty? %i\n", isEmpty(q));
	printf("current top of queue: %s\n", peek(q));
	printf("queue last: %s\n", q->last->message);
	enqueue(q, " world");
	printf("Empty? %i\n", isEmpty(q));
	printf("current top of queue: %s\n", peek(q));
	printf("queue last: %s\n", q->last->message);
	enqueue(q, " this");
	printf("Empty? %i\n", isEmpty(q));
	printf("current top of queue: %s\n", peek(q));
	printf("queue last: %s\n", q->last->message);
	enqueue(q, " is");
	printf("Empty? %i\n", isEmpty(q));
	printf("current top of queue: %s\n", peek(q));
	printf("queue last: %s\n", q->last->message);
	enqueue(q, " a");
	printf("Empty? %i\n", isEmpty(q));
	printf("current top of queue: %s\n", peek(q));
	printf("queue last: %s\n", q->last->message);
	enqueue(q, " message");
	printf("Empty? %i\n", isEmpty(q));
	printf("current top of queue: %s\n", peek(q));
	printf("queue last: %s\n", q->last->message);
	tmp = q->first;
	printf("printing entire queue:\n");
	while (tmp)
	{
		printf("%s", tmp->message);
		tmp = tmp->next; 
	}
	printf("\nremoved %s from queue\n", dequeue(q));
	printf("current top of queue: %s\n", peek(q));
	printf("queue last: %s\n", q->last->message);
	tmp = q->first;
	printf("printing entire queue:\n");
	while (tmp)
	{
		printf("%s", tmp->message);
		tmp = tmp->next; 
	}
	return (0);
}



// Function used for the test
// Don't go further :)

