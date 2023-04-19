#include "main.h"

/**
 * parse_cmd - extracts the command and arguments
 *
 * @cmd: pointer to a string
 * @argv: array of pointers to strings
 *
 * Return: number of tokens
 */
int parse_cmd(char *cmd, char **argv)
{
	int argc = 0, i = 0, len = 0;
	char c, arg[MAX_ARG_LEN], quote = '\0';

	for (i = 0; (c = cmd[i]) != '\0'; i++)
	{
		if (c == '\'' || c == '\"')
		{
			if (!quote)
				quote = c;
			else if (quote == c)
				quote = '\0';
		}
		else if ((c == ' ' || c == '\n') && !quote)
		{
			if (len)
			{
				arg[len] = '\0';
				argv[argc++] = _strdup(arg);
				len = 0;
			}
		}
		else
		{
			if (len >= MAX_ARG_LEN)
				return (-1);
			if (c == '\\' && (cmd[i + 1] == '\"' || cmd[i + 1] == '\''))
				c = cmd[++i];
			arg[len++] = c;
		}
	}

	if (len)
	{
		arg[len] = '\0';
		argv[argc++] = _strdup(arg);
	}

	argv[argc] = NULL;

	return (argc);
}


/**
 * parse_path - extracts existing paths holding
 *				the command
 *
 * @cmd: the command
 *
 * Return: pointer to strings of right paths
 */
char *parse_path(char *cmd)
{
	int i = 0, k = 0, j, len;
	char *value = _getenv("PATH"), *path = malloc(1);
	struct stat st;

	if (value == NULL)
		return (cmd);

	len = _strlen(cmd);

	while (value[i] != '\0')
	{
		while (value[i] != ':' && value[i] != '\0')
			i++;

		path = realloc(path, i - k + len + 2);

		_strncpy(path, value + k, (j = i - k));
		path[j++] = '/';
		_strncpy(path + j, cmd, i - k + len + 2);

		if (stat(path, &st) == 0)
			return (path);

		if (value[i] == '\0')
			break;

		k = ++i;
	}

	free(path);
	return (_strdup(cmd));
}
