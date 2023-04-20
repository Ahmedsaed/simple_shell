#include "main.h"

/**
 * exit_shell - clears all allocated memory and
 * exits the shell
 *
 * @line_buffer: the buffer that contains the command and it's arguments
 * @argv: array of strings
 */
void exit_shell(char *line_buffer, char **argv)
{
	int j;

	for (j = 0; argv[j] != NULL; j++)
		free(argv[j]);
	free(line_buffer);
	exit(0);
}

/**
 * _env - Outputs all environmental variables.
 *
 * Return: nothing.
 */

void _env(void)
{
	int idx;

	for (idx = 0; environ[idx]; idx++)
		printf("%s\n", environ[idx]);
}
