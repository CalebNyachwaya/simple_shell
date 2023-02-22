#include "shell.h"

/**
 * dir_list - list the directories of the $PATH in a linked list
 *
 * @path: PATH where we obtain the directories.
 * @M_GC: parameter to make release of mallocs
 * Return: head
 */

dir_t *dir_list(M_GC, char *path)
{

	dir_t *head;
	char *get_dir;

	head = NULL;
	strtok(path, "=");
	get_dir = strtok(NULL, ":");

	while (get_dir != NULL)
	{
		add_nodeint_end(GC, &head, get_dir);
		get_dir = strtok(NULL, ":");
	}

	return (head);
}
/**
 * find_command - this funtion find the file necesarie to execute the command.
 *
 * @nodo: Node where the directory receives
 * @command: Command that you receive by the user
 * @M_GC: parameter to make release of mallocs
 * Return: The next node plus the required command
 */
char *find_command(M_GC, dir_t *nodo, char *command)
{
	char *current_direction, *slash_command;
	int question;

	if (nodo == NULL)
		return (NULL);

	slash_command = str_concat(GC, "/", command);
  /*here we have something like: /ls*/

	current_direction = str_concat(GC, nodo->directory, slash_command);
  /*here we have something like: /bin/ls*/

	question = access(current_direction, X_OK);
	if (question == 0)
	{
		return (current_direction);
	}
	return (find_command(GC, nodo->next, command));
}
