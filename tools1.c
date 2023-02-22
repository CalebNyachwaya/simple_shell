#include "shell.h"
/**
 * add_nodeint_end - adds a new node at the end of a dir_t list
 * @head: pointer to the list
 * @directory: directory to put in the list
 * @M_GC: parameter to make release of mallocs
 * Return: the address of the new element, or NULL if it failed
 **/
dir_t *add_nodeint_end(M_GC, dir_t **head, char *directory)
{
	dir_t *new_box, *last;

	if (!head)
		return (0);
	new_box = GC->malloc(GC, sizeof(dir_t));
	if (new_box == NULL)
		return (NULL);
	new_box->directory = directory;
	new_box->next = NULL;
	if (*head != NULL)
	{
		last = GC->malloc(GC, sizeof(dir_t));
		if (last == NULL)
		{
			/*if allocate fails, free new_box*/
			return (NULL);
		}
		/*here we only pass a pointer to the first node*/
		last = (*head);
		while (last->next != NULL)
			/*ask for the next node*/
			last = last->next;
		last->next = new_box;
		return (last->next);
	}
	*head = new_box;
	return (*head);
}

/**
 * str_concat - concatenates two strings
 * @s1: string1
 * @s2: string2
 * @M_GC: parameter to make release of mallocs
 * Return: char
 **/
char *str_concat(M_GC, char *s1, char *s2)
{
	char *ptr;
	int j, i;
	char space = 0, len1 = 0, len2 = 0;

	if (s1 == NULL)
		s1 = ("");
	if (s2 == NULL)
		s2 = ("");

	for (i = 0; s1[i]; i++)
		len1++;

	for (j = 0; s2[j]; j++)
		len2++;
	space = len1 + len2;
	ptr = GC->malloc(GC, sizeof(*ptr) * space + 1);
	if (ptr == NULL)
		return (NULL);
	for (j = 0; *(s1 + j); j++)
		*(ptr + j) = *(s1 + j);
	for (i = 0; *(s2 + i); i++, j++)
		*(ptr + j) = *(s2 + i);
	*(ptr + j) = '\0';
	return (ptr);
}

/**
 * copy_path_from_env - This function copies the content of PATH to the env
 *
 * @env: environment which receives the values of PATH
 * @path: path which gives the parameters to copy
 **/
void copy_path_from_env(char **env, char *path)
{
	int i, j;

	for (i = 0; env[i] != NULL; i++)
		if (compare_str(env[i], "PATH"))
			for (j = 0; env[i][j] != '\0'; j++)
				path[j] = env[i][j];
	path[j] = '\0';
}
/**
 * handle_sigint - functio to heandlet the Ctrl + C
 *
 * @sig: signal handled
 */
void handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n$ ", 4);
	}
}
/**
 * _putchar2 - Function to print a character in standard output
 * @character: The character to print
 * Return: always 1
 */
int _putchar2(char character)
{
	write(1, &character, 1);
	return (1);
}
