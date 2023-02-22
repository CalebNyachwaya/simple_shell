#include "shell.h"
/**
 * compare_str - compares two strings and identifies
 * whether they are the same or not
 * @str1: string to compare no 1
 * @str2: string to compare no 2
 * Return: 1 if the strings are the same and 0 if they are not
 **/
int compare_str(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return (0);

	if (*str1 == '\0' || *str2 == '\0')
		return (1);

	return ((*str1 == *str2) && compare_str(str1 + 1, str2 + 1));
}

/**
 * _putchar - Function to print a character in standard error
 * @character: The character to print
 * Return: always 1
 */
int _putchar(char character)
{
	write(STDERR_FILENO, &character, 1);
	return (1);
}
/**
 * _strlen - function to count the length of a string
 * @str: this is a parameter to change.
 * Return: len
 */

int _strlen(char *str)
{
	int len;

	for (len = 0; str && str[len] != '\0'; len++)
	{	}
	return (len);
}
/**
 * print_number - function that prints numbers only
 * @counter: number to print
 */
void print_number(size_t counter)
{
	if (counter / 10)
		print_number(counter / 10);

	_putchar(counter % 10 + '0');
}

/**
 * print_env - function to print env
 * @env: enviroment
 * Return: o on success
 **/
int print_env(char **env)
{
	unsigned int i = 0, j;

	while (env[i] != NULL)
	{
		for (j = 0; env[i][j] != '\0'; j++)
		{
			_putchar2(env[i][j]);
		}
		_putchar2('\n');
		i++;
	}
	return (0);
}
