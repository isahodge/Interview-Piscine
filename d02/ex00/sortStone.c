#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void sortStones(struct s_stone **stone)
{
	struct s_stone *list;
	struct s_stone *tmp;
	struct s_stone *prev;
	struct s_stone **table;
	struct s_stone **check_alloc;
	int i = 0;
	int j = 0;
	int val = 0;

	table = NULL;
	list = (*stone);
	if (!list)
		return;
	val = list->size;
	//create table
	table = realloc(table, i + 1);
	table[i] = list;
	tmp = list;
	prev = NULL;
	while (list)
	{
		if (list->size != val)
		{
			i++;
			val = list->size;
			prev ? prev->next = NULL : 0;
			check_alloc = realloc(table, sizeof(*check_alloc) * (i + 1));
			if (!check_alloc)
			{
				printf("Realloc failed\n");
				return ;
			}
			else
				table = check_alloc;
			table[i] = list;
		}
		prev = list;
		list = list->next;
	}
	//printf("printing unsorted table\n");
	j = 0;
	while (j <= i)
	{
		//printf("index[%i] %i\n", j, table[j] ? table[j]->size: -1);
		j++;
	}
	//bubble sort table
	int swap = 1;
	while (swap)
	{
		swap = 0;
		j = 0;
		while (j <= i)
		{
			//printf("j[%i], i[%i]\n", j, i);
			if (j < i && table[j + 1] && table[j] && table[j]->size > table[j + 1]->size)
			{
				//printf("j[%i] swapping %i and %i\n", j, table[j]->size, table[j + 1]->size);
				swap = 1;
				tmp = table[j];
				table[j] = table[j + 1];
				table[j + 1] = tmp;
			}
			j++;
		}
	}
	//printf("printing sorted table\n");
	j = 0;
	while (j <= i)
	{
		//printf("index[%i] %i\n", j, table[j] ? table[j]->size: -1);
		j++;
	}
	//reconnect list from table
	//printf("reconnecting\n");
	j = 0;
	(*stone) = table[j];
	while (j <= i)
	{
		if (table[j])
			tmp = table[j];
		while (tmp->next)
			tmp = tmp->next;
		if (j < i && table[j + 1])
			tmp->next = table[j + 1];
		j++;
	}
}	
