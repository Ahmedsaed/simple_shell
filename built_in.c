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
 * _env - prints all environmental variables.
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
	char *home, *username, *result, *tmp;

	username = _getenv("USERNAME");

	if (username == NULL)
		return (NULL);

	len = _strlen(username);
	home = (char *)malloc(sizeof(char) * (7 + len));
	home[0] = '\0';

	if (home == NULL)
		return (NULL);

	_strcat(home, "/home/");
	_strcat(home, username);
	len = _strlen(home);
	path_len = _strlen(str);

	result = (char *)malloc(sizeof(char) * (len + path_len + 1));
	result[0] = '\0';

	if (result == NULL)
		return (NULL);

	if (_strncmp(str, home, len) == 0)
	{
		_strcat(result, "~");
		tmp = _substr(str, len + 1, path_len);
		_strcat(result, tmp);
		free(tmp);
	}

	free(home);
	return (result);
}

/**
 * change_dir - changes the directory of the process
 *
 * @dir: string - new directory
 *
 * Return: 0 on sucess, 1 on failure
 */
int change_dir(char *dir)
{
	char cwd[PATH_MAX];

	if (dir == NULL)
		dir = _strdup(_getenv("HOME"));

	else if (_strcmp(dir, "-") == 0)
	{
		dir = _strdup(_getenv("OLDPWD"));
		if (dir == NULL)
			dir = _getenv("PWD");

		print_str(dir);
		print_str("\n");
	}
	else
		dir = _strdup(dir);

	if (_setenv("OLDPWD", _getenv("PWD")) == -1)
	{
		print_err("Failed to update OLDPWD env variable");
		return (1);
	}

	if (chdir(dir) == -1)
	{
		free(dir);
		perror(prog_name);
		return (1);
	}

	free(dir);
	if (_setenv("PWD", getcwd(cwd, sizeof(cwd))) == -1)
	{
		print_err("Failed to update PWD env variable");
		return (1);
	}

	return (0);
}
