#include "header.h"
#include <stdio.h>
#include <string.h>

int	searchPrice(struct s_art **arts, int n, char *name)
{
	int mid;
	int left;
	int right;

	mid = 0;
	left = 0;
	right = n;
	if (!arts)
		return (-1);
	if (right <= 0)
		return (-1);
	while (left < right)
	{
		//printf("left[%i] right[%i]\n", left, right);
		//printf("mid[%s], [%s]\n", arts[mid]->name, name);
		mid = (left + (right - 1)) / 2;
		if (!strcmp(arts[mid]->name, name))
			return (mid);
		else if (strcmp(arts[mid]->name, name) < 0)
		{
			printf("assigning right\n");
			left = mid + 1;
		}
		else if (strcmp(arts[mid]->name, name) > 0)
		{
			printf("assigning left\n");
			right = mid - 1;
		}
	}
	return (-1);
}

/*int	searchPrice(struct s_art **arts, int left, int right, char *name)
{
	int mid;

	mid = 0;
	mid = left + (right - 1) / 2;
	printf("left[%i] right[%i]\n", left, right);
	if (!arts)
		return (-1);
	if (right <= 0)
		return (-1);
	if (!strcmp(arts[mid]->name, name))
		return (mid);
	if (strcmp(arts[mid]->name, name) < 0)
		return (searchPrice(arts, mid + 1, right, name));
	if (strcmp(arts[mid]->name, name) > 0)
		return (searchPrice(arts, left, mid - 1, name));
	return (-1);
}*/
