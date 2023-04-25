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

/**
 * format_tilde - search string for home/@USERNAME
 *			            if exists, change it to ~.
 *
 * @str: string to search for.
 * Return: string
 */

char *format_tilde(char *str)
{
	int len = 0, path_len = 0;
	char *home, *username, *result;

	username = _getenv("USERNAME");
	len = _strlen(username);
	home = (char *)malloc(sizeof(char *) * (7 + len));

	if (home == NULL)
		return (NULL);

	home = _strcat(home, "/home/");
	home = _strcat(home, username);
	len = _strlen(home);
	path_len = _strlen(str);

	result = (char *)malloc(sizeof(char *) * (len + path_len + 1));

	if (result == NULL)
		return (NULL);

	if (_strncmp(str, home, len) == 0)
	{
		_strcat(result, "~");
		_strcat(result, _substr(str, len + 1, path_len));
	}

	return (result);
}
