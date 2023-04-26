#include "main.h"

/**
 * handle_variables - handle variable replacment for arguments
 *
 * @argv: a pointer to an array of arguments
 */
void handle_variables(char **argv)
{
	int i;
	char *value;

	for (i = 0; argv[i] != NULL; i++)
	{
		if (argv[i][0] == '$')
		{
			value = _getenv(argv[i] + 1);
			if (value == NULL)
			{
				argv[i][0] = '\0';
				continue;
			}

			argv[i] = _realloc(argv[i],
					sizeof(char) * _strlen(argv[i]),
					sizeof(char) * (_strlen(value) + 1));
			_strcpy(argv[i], value);
		}
	}
}
