#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *console(void)
{
	char *line;
	size_t	bufsize;

	bufsize = 255;
	line = (char*)malloc(bufsize);
	do
	{
		printf("?: ");
		getline(&line, &bufsize, stdin);
		printf("You typed %s\n", line);
	}
	while (strcmp("SEND\n", line));
	return (
}
