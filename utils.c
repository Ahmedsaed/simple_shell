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

