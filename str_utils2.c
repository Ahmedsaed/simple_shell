#include "main.h"

/**
 * _strlen - returns length of string
 *
 * @s: string
 * Return: length of string
 */

int _strlen(char *s)
{
	int count;

	for (count = 0; s[count] != '\0'; count++)
		;

	return (count);
}

/**
 * _strcat - concatenate to strings
 *
 * @dest: destination string
 * @src: source string
 *
 * Return: dest if exists
 */

char *_strcat(char *dest, char *src)
{
	char *ptr = dest + _strlen(dest);

	if (dest == NULL)
		return (NULL);

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}
