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
 * print_err - prints error to stderr
 *
 * @s: error message to print.
 */
void print_err(char *s)
{
	int i;

	i = _strlen(s);

	write(STDERR_FILENO, s, i);
}
