#include "main.h"

/**
 * exit_shell - clears all allocated memory and
 * exits the shell
 *
 * @line_buffer: the buffer that contains the command and it's arguments
 * @argv: array of strings
 */
void exit_shell(char *line_buffer, char **argv)
{
	int j;

	for (j = 0; argv[j] != NULL; j++)
		free(argv[j]);
	free(line_buffer);
	exit(0);
}

/**
 * _env - Outputs all environmental variables.
 *
 * Return: nothing.
 */

void _env(void)
{
	int idx;

	for (idx = 0; environ[idx]; idx++)
		printf("%s\n", environ[idx]);
}

/**
 * _memcpy - memory copies to another
 *			location until a certain
 *              memory block.
 *
 * @dest: destination
 * @src: source
 * @n: until a certain memory block.
 */
void _memcpy(void *dest, void *src, size_t n)
{
	size_t i;
	char *cdest = (char *)dest;
	char *csrc = (char *)src;

	for (i = 0; i < n; i++)
		cdest[i] = csrc[i];
}
