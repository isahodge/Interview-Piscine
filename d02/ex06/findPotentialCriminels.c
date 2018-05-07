#include "header.h"
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void countSortV2(struct s_criminal **criminals, int n, int exp)
{
	int arr[10];
	struct s_criminal *cpy[n];
	
	bzero(arr, 10 * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		arr[(criminals[i]->description/exp) % 10] += 1;
		cpy[i] = criminals[i];
	}
	for(int i = 0; i < 10; i++)
	{
		printf("bucket[%i] val [%i]\n", i, arr[i]);
		if (i)
			arr[i] += arr[i - 1];
	}
	for (int i = 0; i < n; i++)
	{
		cpy[arr[ (criminals[i]->description/exp)%10 ] - 1] = criminals[i];
        arr[ (criminals[i]->description/exp)%10 ]--;
	}
	for (int i = 0; i < n; i++)
	{
		criminals[i] = cpy[i];
	}
	/*for (int i = 0; i < n; i++)
	{
		criminals[arr[(cpy[i]->description/exp) % 10] - 1] = cpy[i];
		arr[(cpy[i]->description/exp) % 10]--;
	}*/
}
//int getDescription(void)
//int getDescription(struct s_info *info)
//{
	/*description =
gender * 10^6
+ height * 10^5
+ hairColor * 10^4
+ eyeColor * 10^3
+ glasses * 10^2
+ tattoo * 10^1
+ piercing * 10^0*/

//	int d;
	/*int val = info.height > 149 ? info.height - 150 : 0;
	int height = 0;
	while (val >= 10)
	{
		height++;
		val /= 10;
	}
	info.height > 149 ? height++ : 0;*/
//	d = ((int)pow(10,6) * info->gender) + ((int)pow(10,5) * info->height) + ((int)pow(10,4) * info->hairColor) +
//		((int)pow(10,3) * info->eyeColor) + ((int)pow(10,2) * info->glasses) + ((int)pow(10,1) * info->tattoo) +
//		((int)pow(10,0) * info->piercing);
	/*d = ((int)pow(10,6) * 0) + ((int)pow(10,5) * 3) + ((int)pow(10,4) * 5) +
		((int)pow(10,3) * 2) + ((int)pow(10,2) * 1) + ((int)pow(10,1) * 0) +
		((int)pow(10,0) * 0); */
//	return (d);
//}
void sortCriminals(struct s_criminal **criminals)
{
	//int max_dig = 7;
	for (int exp = 1; 1111111 / exp > 0; exp *= 10)
	{
		countSortV2(criminals, 500000, exp);
	}
}

/*struct s_criminal **findPotentialCriminals(struct s_criminal **criminals, struct s_info *info)
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
			//printf("assigning right\n");
			left = mid + 1;
		}
		else if (strcmp(arts[mid]->name, name) > 0)
		{
			//printf("assigning left\n");
			right = mid - 1;
		}
	}
	return (-1);
}*/
