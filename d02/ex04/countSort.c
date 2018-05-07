#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

void countSort(unsigned char *utensils, int n)
{
	int arr[16];
	unsigned char cpy[n];
	
	bzero(arr, 16 * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		arr[(int)utensils[i]] += 1;
		cpy[i] = utensils[i];
	}
	for(int i = 0; i < 16; i++)
	{
		if (i)
			arr[i] += arr[i - 1];
	}
	for (int i = 0; i < n; i++)
	{
		utensils[arr[cpy[i]] - 1] = cpy[i];
		arr[cpy[i]]--;
	}
}
