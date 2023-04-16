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
	int argc = 0, i = 0, len = 0, j = 0;
	char c, arg[MAX_ARGS + 1];

	while (cmd[i] != '\0')
	{
		while (cmd[i] == ' ' || cmd[i] == '\n')
			i++;

		if (cmd[i] == '\0')
			break;

		len = 0;
		while ((c = cmd[i]) != '\0' && c != ' ' && c != '\n')
		{
			arg[len] = c;
			i++;
			len++;
		}
		arg[len] = '\0';

		argv[argc] = malloc(len + 1);
		if (argv[argc] == NULL)
			return (-1);

		for (j = 0; j < len + 1; j++)
			argv[argc][j] = arg[j];

		argc++;
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
 * Returns: pointer to strings of right paths
 */

char *parse_path(char *cmd)
{
	int i = 0, k = 0, j, len;
	char *value = _getenv(cmd);

	for(len = 0; cmd[len] != '\0'; len++)

	while (value[i] != '\0')
	{
		if (value[i] != ':' && value[i] != '\0')
		{
			char path[i + len + 1];

			for (j = 0; j < i; j++)
				path[j] = value[i];

			path[j++] = '/';

			for (; j < len; j++)
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
