#include "header.h"
#include <stdio.h>

void recurse(struct s_node *lst, int level)
{
	if (lst)
	{
		recurse(lst->next, ++level);
		if (level != 1)
			printf("%s ", lst->word);
		else
			printf("%s\n", lst->word);
	}
}

void printReverse(struct s_node *lst)
{
	recurse(lst, 0);
}

/*void printReverse(struct s_node *lst)
{
	if (lst)
	{
		printReverse(lst->next);
		if (lst->next)
			printf(" %s", lst->word);
		else
			printf("%s", lst->word);
	}
}*/
