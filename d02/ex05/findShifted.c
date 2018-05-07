#include "header.h"
#include <stdlib.h>
#include <stdio.h>

int searchShifted(int *rocks, int length, int value)
{
	int mid;
	int left;
	int right;

	mid = 0;
	left = 0;
	right = length;
	if (!rocks)
		return (-1);
	if (right <= 0)
		return (-1);
	while (left < right)
	{
		mid = (left + (right - 1)) / 2;
		if (rocks[mid] ==  value)
			return (mid);
		else if (rocks[mid] <= rocks[left] && value < rocks[mid])//left side unsorted
			right = mid - 1;
		else if (rocks[mid] >= rocks[right] && value > rocks[mid])//right side unsorted
			left = mid + 1;
		else//treat it like it's sorted
		{
			if (value > rocks[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
	}
	return (-1);
}
