#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void	sort_list(struct s_player **players, int left, int right, int middle, int length)
{
	struct s_player *tmp[right-left+1];
	int start = left;
	int mid = middle + 1;
	int j = 0;
	(void)length;
	for (int i = left; i <= right; i++)
	{
		if (start > middle)
			tmp[j++] = players[mid++];
		else if (mid > right)
			tmp[j++] = players[start++];
		else if (players[start]->score >= players[mid]->score)
			tmp[j++] = players[start++];
		else
			tmp[j++] = players[mid++];
	}
	for (int k = 0; k < j; k++)
	{
		players[left++] = tmp[k];
	}
}

void merge(struct s_player **player, int left, int right, int length)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		merge(player, left, middle, length);
		merge(player, middle + 1, right, length);
		sort_list(player, left, right, middle, length);
	}
}

struct s_player **mergeSort(struct s_player **players)
{
	int i = 0;

	while (players[i])
		i++;
	merge(players, 0, i - 1, i - 1);
	return (players);
}
