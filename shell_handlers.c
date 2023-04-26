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

/**
 * handle_aliases - handle alias replacment for arguments
 *
 * @argv: a pointer to an array of arguments
 */
void handle_aliases(char **argv)
{

	int i, j, len;
	char *alias_env, *alias_value;

	alias_env = _getenv("alias");
	if (alias_env == NULL)
		return;

	for (i = 0; argv[i] != NULL; i++)
	{
		len = _strlen(argv[i]);
		alias_value = alias_env;

		for (j = 0; alias_env[j] != '\0'; j++)
		{
			if (alias_env[j] == ':')
			{
				if (_strncmp(alias_value, argv[i], len) == 0)
				{
					alias_env[j] = '\0';
					argv[i] = _realloc(argv[i],
							sizeof(char) * _strlen(argv[i]),
							sizeof(char) * _strlen(alias_value) + 1);
					_strncpy(argv[i],
							alias_value + len + 2,
							_strlen(alias_value) - len - 3);
					alias_env[j] = ':';
					break;
				}
				else
					alias_value = alias_env + j + 1;
			}
		}
	}
}
