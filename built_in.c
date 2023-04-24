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
	int j, status = 0;

	if (argv[1] != NULL)
		status = _atoi(argv[1]);

	for (j = 0; argv[j] != NULL; j++)
		free(argv[j]);
	free_env();
	free(line_buffer);

	exit(status);
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
	{
		print_str(environ[idx]);
		print_str("\n");
	}
}


