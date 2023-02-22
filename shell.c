#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ; 

int main(__attribute__((unused)) int argc, char **argv)
{
	char *str = NULL;
	size_t n;
	char *stkn;
	pid_t mypid;
	int i;
	char **arr;

	while (1)
	{
	printf("$ ");
	getline(&str, &n, stdin);

	stkn = strtok(str, " \n");/*solves the issue of executing command*/

	arr = malloc(sizeof(char *) * 32);

	arr[0] = stkn;
/*
	if (strcmp(arr[0], "exit") == 0)
		exit(0);
*/
	i = 1;

	while (stkn != NULL)
	{
		stkn = strtok(NULL, " \n");
		arr[i] = stkn;
		i++;
	}
/*&	if (strcmp(arr[0], "exit") == 0 && (arr[1] == NULL))
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
*/
	mypid = fork();
	if (mypid == -1)
	{
		perror("Error");
		return (1);
	}
	else if (mypid == 0)/*solves the issue of exiting*/
	{
		if (execve(arr[0], arr, NULL) == -1)
		{
			perror(argv[0]);
			return (0);
		}
	}
	else
	{
		wait(NULL);/*suspends the parent from action until the child finishes*/
	}
	}

	free(str);
	return (0);
}
