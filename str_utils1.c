#include "main.h"

/**
 * print_str - prints a string to stdout
 *
 * @s: pointer to an array of chars
 */

void print_str(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	write(STDOUT_FILENO, s, i);
}


/**
 * _strcmp - compares two strings
 *
 * @s1: first string
 * @s2: second string
 *
 * Return: integer less than/equal to/greater than if s1 is found
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);

	return (0);
}


/**
 * _strncmp - compares two strings until n
 *
 * @s1: first string
 * @s2: second string
 * @n: the first n length to compare
 *
 * Return: integer less than/equal to/greater than if s1 is found
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	while (n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return (*s1 - *s2);
	}
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

	while (s[len] != '\0')
		len++;
	len++;

	copy = malloc(len * sizeof(char));

	if (copy != NULL)
	{
		for (i = 0; i < len; i++)
			copy[i] = s[i];
	}

	return (copy);
}

/**
 * _strncpy - copies from source to destination
 *				until n characters.
 *
 * @dest: destination
 * @src: source
 * @n: number of characters to copy to
 *
 * Return: destination if exists, otherwise null.
 */

char *_strncpy(char *dest, char *src, size_t n)
{
	char *ptr;

	if (dest == NULL)
		return (NULL);

	ptr = dest;

	while (*src && n--)
		*ptr++ = *src++;

	*ptr = '\0';

	return (dest);
}
