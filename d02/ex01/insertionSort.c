#include "header.h"
#include <stdlib.h>

void insertionSort(struct s_player **players)
{
	int i = 0;
	int j;
	struct s_player *insert;
	while (players[i])
	{
		j = 0;
		while (players[j])
		{
			if (players[i]->score > players[j]->score)
			{
				insert = players[i];
				players[i] = players[j];
				players[j] = insert;
			}
			j++;
		}
		i++;
	}
}
