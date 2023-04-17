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
	char c, arg[MAX_ARGS + 1], quote = '\0';

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
			if (len >= MAX_ARGS)
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
	char *value = _getenv(cmd), *path;

	for (len = 0; cmd[len] != '\0'; len++)
		;

	while (value[i] != '\0')
	{
		if (value[i] != ':' && value[i] != '\0')
		{
			path = malloc(i + len + 1);

			for (j = 0; j < i; j++)
				path[j] = value[j];

			path[j++] = '/';

			for (; j < len + 1; j++)
			{
				path[j] = cmd[k];
				k += 1;
			}

			return (path);
		}
		else
			i++;
	}

	return (cmd);
}
