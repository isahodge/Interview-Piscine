#include "header.h"
#include <stdlib.h>
#include <string.h>

void	swap(struct s_player **player1, struct s_player **player2)
{
	struct s_player *tmp;

	tmp = *player1;
	*player1 = *player2;
	*player2 = tmp;
}

int		partition(struct s_player **players, int low, int high)
{
	struct s_player *pivot;
	int i;
	int j;

	pivot = players[high];
	i = low - 1;//keeps track of where we need to place the pivot
	j = low;
	while (j <= high - 1)
	{
		if (players[j]->score > pivot->score)//does lexical comparison of the characters in name
		{
			i++;
			swap(&(players[i]), &(players[j]));//i will always be on the smaller side of where the pivot will be placed
		}
		j++;
	}
	swap(&(players[i + 1]), &(players[high]));//place pivot right after all the smaller elements
	return (++i);
}

void	recurse(struct s_player **players, int low, int high)
{
	int part;

	part = 0;
	if (low < high)//if low == high, we've reached only 1 item in the subarray (already sorted)
	{
		part = partition(players, low, high);
		recurse(players, low, part - 1);
		recurse(players, part + 1, high);
	}
}
void quickSort(struct s_player **players)
{
	int i = 0;
	while (players[i])
	{
		i++;//finding the length of the list
	}
	recurse(players, 0, i - 1);
}
