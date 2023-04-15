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
	int i, j, len, k, n;

	n = get_token_count(cmd);
	argv = malloc(sizeof(char *) * (n + 1));

	for (i = 0, len = 0, k = 0; 1; i++)
	{
		if ((cmd[i] == ' ' || cmd[i] == '\0') && len != 0)
		{
			argv[k] = malloc(sizeof(char) * len + 1);
			for (j = i - len; j < len; j++)
				argv[k][j] = cmd[j];
			argv[k][len] = '\0';
			k++;
			len = 0;
		}
		else
			len++;

		if (cmd[i] == '\0')
			break;
	}

	argv[k] = NULL;

	return (n);
}

/**
 * get_token_count - returns the number of tockens
 *
 * @s: string
 *
 * Return: number of tockens
 */
int get_token_count(char *s)
{
	int n = 0, i = 0, len = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
		{
			if (len == 0)
				continue;

			n += 1;
			len = 0;
		}
		else
			len++;
	}

	if (len != 0) n++;

	return (n);
}
