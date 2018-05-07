#include "header.h"
#include <stdlib.h>
#include <stdio.h>

struct s_tank *initTank(void)
{
	struct s_tank *tank;

	if (!(tank = (struct s_tank*)malloc(sizeof(struct s_tank))))
		return (NULL);
	tank->n = 0;
	tank->stacks = NULL;
	return (tank);
}

void tankPush(struct s_tank *tank, int energy)
{
	struct s_stack *new_stack;
	struct s_elem *new_elem;
	int i;

	i = 0;
	if (energy < 10 || energy > 100 || !tank)
	{
		printf("Failed to add energy to tank\n");
		return ;
	}
	if (!tank->stacks || (tank->stacks && tank->stacks[tank->n - 1]->sum + energy > 1000))
	{
		new_stack = (struct s_stack *)malloc(sizeof(struct s_stack));
		new_stack->elem = NULL;
		tank->n++;
		tank->stacks = (struct s_stack**)realloc(tank->stacks, tank->n);
		tank->stacks[tank->n - 1] = new_stack;
	}
	new_elem = (struct s_elem *)malloc(sizeof(struct s_elem));
	new_elem->energy = energy;
	new_elem->next = tank->stacks[tank->n - 1]->elem;
	tank->stacks[tank->n - 1]->elem = new_elem;
	tank->stacks[tank->n - 1]->sum += energy;
}

int tankPop(struct s_tank *tank)
{
	struct s_elem *elem;

	if (tank && tank->stacks && tank->stacks[tank->n - 1])	
	{
		elem = tank->stacks[tank->n - 1]->elem;
		tank->stacks[tank->n - 1]->elem = elem->next;
		tank->stacks[tank->n - 1]->sum -= elem->energy;
		if (!elem->next)
		{
			free(tank->stacks[tank->n - 1]);
			tank->stacks[tank->n - 1] = NULL;
			tank->n--;
			if (tank->n == 0)
			{
				free(tank->stacks);
				tank->stacks = NULL;
			}
		}
		elem->next = NULL;
		return (elem->energy);
	}
	printf("Failed to pop\n");
	return (-1);
}
