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

/**
 * _strdup - returns a pointer to a copy of a string
 *
 * @s: string to be copied
 *
 * Return: pointer to new copy
 */

char *_strdup(char *s)
{
	char *copy = NULL;
	size_t len = 0, i;

	if (s == NULL)
		return (NULL);

	len = _strlen(s) + 1;

	copy = malloc(len * sizeof(char));

	if (copy != NULL)
	{
		for (i = 0; i < len; i++)
			copy[i] = s[i];
	}

	return (copy);
}

