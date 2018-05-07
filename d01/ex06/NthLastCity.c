#include "header.h"
#include <stdlib.h>

char *NthLastCity(struct s_city *city, int n)
{
	struct s_city *tmp;
	int i;

	tmp = city;
	i = 0;
	if (!city)
		return (NULL);
	while (tmp)
	{
		if (i > n)
			city = city->next;
		i++;
		tmp = tmp->next;
	}
	return (city->name);
}
