#include "main.h"

/**
 * _strlen - returns length of string
 *
 * @s: string
 * Return: length of string
 */

size_t _strlen(char *s)
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
	char *ptr;

	if (dest == NULL)
		return (NULL);

	ptr = dest + _strlen(dest);

	while (*src != '\0')
		*ptr++ = *src++;

	*ptr = '\0';

	return (dest);
}
