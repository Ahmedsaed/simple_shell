#include "main.h"

/**
 * print_str - prints a string to stdout
 *
 * @s: pointer to an array of chars
 */

void print_str(char *s)
{
	int i;

	i = _strlen(s);

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
 * _strcpy - copies from source to destination
 *
 * @dest: destination
 * @src: source
 *
 * Return: destination if exists
 *
 * note: to avoid segmentation fault or wrong output,
 *					Size Of Dest + 1 < Size Of Src.
 */

char *_strcpy(char *dest, char *src)
{
	char *ptr;

	if (dest == NULL)
		return (src);
	if (src == NULL)
		return (NULL);

	ptr = dest;

	while (*src)
		*ptr++ = *src++;

	*ptr = '\0';

	return (dest);
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
 *
 * note: to avoid segmentation fault or wrong output,
 *					Size Of Dest + 1 < n.
 */

char *_strncpy(char *dest, char *src, size_t n)
{
	char *ptr;

	if (dest == NULL)
		return (src);
	if (src == NULL)
		return (NULL);

	ptr = dest;

	while (*src && (n-- != 0))
		*ptr++ = *src++;

	*ptr = '\0';

	return (dest);
}
