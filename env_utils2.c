#include "main.h"

/**
 * _getenvLen - gets the number of variables
 *				inside an environment.
 * Return: number of variables.
 */
int _getenvLen(void)
{
	int count;

	for (count = 0; environ[count] != NULL; count++)
		;

	return (count);
}


