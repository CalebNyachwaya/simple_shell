#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ; 

int main()
{
	char *str = NULL;
	char *stkn;
	size_t n;
	int i;
	char **arr;

	while (1)
	{
	printf("$ ");
	getline(&str, &n, stdin);

	stkn = strtok(str, " \n");/*solves the issue of executing command*/

	arr = malloc(sizeof(char *) * 32);

	arr[0] = stkn;
	i = 1;

	while (stkn != NULL)
	{
		stkn = strtok(NULL, " \n");
		arr[i] = stkn;
		i++;
	}
	if (strcmp(arr[0], "exit") == 0 && (arr[1] == NULL))
		exit(0);
	if (strcmp(arr[0], "exit") == 0 && (arr[1] == NULL))
	{
		i = 0;
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i]);
			i++;
		}                
		continue;
	}
	}
}
