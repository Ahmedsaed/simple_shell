#include "main.h"

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

/**
 * _getenv - Gets an environmental variable.
 *
 * @var: the name of the environmental variable.
 *
 * Return: Null if environmental variable doesnt exist.
 *		   Otherwise, value of environmental variable.
 */

char *_getenv(char *var)
{
	int idx, len;

	if (var == NULL)
		return (NULL);

	len = _strlen(var);

	for (idx = 0; environ[idx]; idx++)
	{
		if (_strncmp(var, environ[idx], len) == 0)
			return (environ[idx] + len + 1);
	}

	return (NULL);
}

/**
 * _setenv - sets an environmental variable,
 *			if exists, check if it is to be overwritten
 *			then overwrite it, otherwise dont overwrite.
 *			if doesn't exist, add it.
 *
 * @name: key
 * @value: value
 * @overwrite: bool to check if you want it overwritten
 *
 * Return: 0 if successful, -1 if not.
 *
 * note: if envname refers to a string with "=",
 *								setenv must fail.
 *		 if name is empty, setenv must fail.
 * if setenv fails, must print EINVAL from <errno.h>.
 */

int _setenv(char *name, char *value, int overwrite)
{
	char *ev;

	if (name == NULL || value == NULL || name[0] == '\0'
			|| _strchr(name, '=') != NULL)
	{
		printf("Error: Invalid argument.\n");
		return (-1);
	}

	if (_getenv(name) != NULL && overwrite == 0)
		return (0);

	ev = malloc(_strlen(name) + _strlen(value + 2));

	if (ev == NULL)
		return (-1);

	_strcpy(ev, name);
	_strcat(ev, "=");
	_strcat(ev, value);

	return (0);
}
