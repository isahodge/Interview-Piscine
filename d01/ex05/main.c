#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

#include "header.h"

void print_stack(struct s_tank *tank)
{
	int i = 0;
	if (!tank->stacks || !tank->stacks[tank->n - 1])
		return ;
	printf("\nprinting stacks:\n");
	while (i < tank->n)
	{
		printf("stack[%i] sum[%i]\n", i, tank->stacks[i]->sum);
		i++;
	}
	printf("\n");
}

void print_elems(struct s_tank *tank)
{
	struct s_elem *elem;

	if (!tank->stacks || !tank->stacks[tank->n - 1])
		return ;
	elem = tank->stacks[tank->n - 1]->elem;
	printf("\nprinting all elems in stacks:\n");
	while (elem)
	{
		printf("elem: %i\n", elem->energy);
		elem = elem->next;
	}
	printf("\n");
}

int main(void)
{
	struct s_tank *tank = initTank();

	/*-------------------
	launch your test here
	--------------------*/
	tankPush(tank, 10);
	printf("tank->n [%i]\n", tank->n);
	printf("tank->stack->sum [%i]\n", tank->stacks[tank->n - 1]->sum);
	tankPush(tank, 50);
	printf("tank->n [%i]\n", tank->n);
	printf("tank->stack->sum [%i]\n", tank->stacks[tank->n - 1]->sum);
	tankPush(tank, 950);
	printf("tank->n [%i]\n", tank->n);
	printf("tank->stack->sum [%i]\n", tank->stacks[tank->n - 1]->sum);

	print_elems(tank);

	tankPush(tank, 1000);
	printf("tank->n [%i]\n", tank->n);
	printf("tank->stack->sum [%i]\n", tank->stacks[tank->n - 1]->sum);
	//printf("tank->stack->sum [%i]\n", tank->stacks[tank->n - 2]->sum);

	print_stack(tank);

	printf("pop elem %i\n", tankPop(tank));
	print_stack(tank);
	print_elems(tank);

	printf("pop elem %i\n", tankPop(tank));
	print_stack(tank);
	print_elems(tank);

	printf("pop elem %i\n", tankPop(tank));
	print_stack(tank);
	print_elems(tank);
	printf("pop elem %i\n", tankPop(tank));

	tankPush(tank, 1000);
	print_stack(tank);
	print_elems(tank);
	return (0);
}



// Function used for the test
// Don't go further :)
