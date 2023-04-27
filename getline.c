#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * _getline - reads characters from stdin into buffer untill it
 * reaches '\n' or EOF characters
 *
 * @lineptr: the buffer that the function should update each call
 * @n: the size of the line_buffer after update
 * @stream: the stream that the function should read the characters from
 *
 * Return: On  success, return  the  number of characters read,
 * including the delimiter character, but not including the
 * terminating null byte ('\0'). This value can be used to
 * handle embedded null bytes in the line read.
 *
 * return -1 on failure to read a line (including end-of-file condition).
 * the buffer should be freed by the user program even on failure.
 */
ssize_t _getline(char **lineptr, size_t *n, int stream)
{
	ssize_t count = 0;
	ssize_t bytes_read = 0;
	char c = 0;

	if (lineptr == NULL || n == NULL)
	{
		errno = EINVAL;
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*lineptr = malloc(128);
		if (*lineptr == NULL)
			return (-1);
		*n = 128;
	}


	while ((bytes_read = read(stream, &c, 1)) > 0)
	{
		if (count >= (ssize_t)(*n - 1))
		{
			char *new_lineptr;

			*n *= 2;
			new_lineptr = _realloc(*lineptr, _strlen(*lineptr), *n);
			if (new_lineptr == NULL)
				return (-1);
			*lineptr = new_lineptr;
		}
		(*lineptr)[count++] = c;
		if (c == '\n')
			break;
	}

	if (count == 0)
		return (-1);
	(*lineptr)[count] = '\0';
	return (count);
}
