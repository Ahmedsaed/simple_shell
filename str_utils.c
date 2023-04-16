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
