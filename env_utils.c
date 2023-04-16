#include "main.h"

/**
 * _getenv - Gets an environmental variables.
 * @var: the name of the environmental variable.
 *
 * Return: Null if environmental variable doesnt exist.
 *		   Otherwise, value of environmental variable.
 */

char *_getenv(char *var, char *env[])
{
	int idx, len;

	for(len = 0; var[len] != '\0'; len++)
		;

	for(idx = 0; env[idx]; idx++)
	{
		if (_strncmp(var, env[idx], len) == 0)
			return (env[idx]+len+1);
	}

	return (NULL);
}
