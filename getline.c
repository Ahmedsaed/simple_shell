#include "main.h"

/**
 * _getline - reads characters from stdin into buffer untill it
 * reaches '\n' or EOF characters
 *
 * @line_buffer: the buffer that the function should update each call
 * @n: the size of the line_buffer after update
 * @stream: the that the function should read the characters from
 *
 * Return: On  success, return  the  number of characters read,
 * including the delimiter character, but not including the
 * terminating null byte ('\0'). This value can be used to
 * handle embedded null bytes in the line read.
 *
 * return -1 on failure to read a line (including end-of-file condition).
 * the buffer should be freed by the user program even on failure.
 */
int _getline(char **lineptr, size_t *n, int stream)
{
	static char *buffer, *buffer_ptr;
	static size_t current_buffer_size, bytes_read;
	size_t total_bytes = 0;
	int r = 0;
	char *new_buffer = NULL;

	if (lineptr == NULL || n == NULL)
		return (-1);

	if (buffer == NULL)
	{
		current_buffer_size = BUFFER_SIZE;
		buffer = malloc(current_buffer_size);
		if (buffer == NULL)
			return (-1);
		buffer_ptr = buffer;
	}

	while (1)
	{
		if (buffer_ptr < buffer + bytes_read)
		{
			char *new_line = getline_memchr(buffer_ptr,
					'\n',
					buffer + bytes_read - buffer_ptr);

			if (new_line != NULL)
			{
				size_t line_len_b = new_line - buffer_ptr;

				if (*lineptr == NULL || *n < line_len_b)
				{
					new_buffer = _realloc(*lineptr, *n * sizeof(char), line_len_b * sizeof(char));
					*n = line_len_b;
					if (new_buffer == NULL)
						return (-1);
					*lineptr = new_buffer;
				}

				_strncpy(*lineptr + total_bytes, buffer_ptr, line_len_b);
				buffer_ptr += line_len_b + 1;
				total_bytes += line_len_b;
				return (total_bytes);
			}
		}

		if (buffer + bytes_read == buffer + current_buffer_size)
		{
			current_buffer_size *= 2;
			new_buffer = _realloc(buffer, current_buffer_size / 2, current_buffer_size);
			if (new_buffer == NULL)
				return (-1);
			buffer = new_buffer;
			buffer_ptr = buffer + bytes_read;
		}

		r = read(stream, buffer + bytes_read, current_buffer_size - bytes_read);
		if (r == 0)
			return (-1);
		else if (r < 0)
		{
			/*perror(prog_name);*/
			return (-1);
		}
		bytes_read += r;
	}
}

/**
 * getline_memchr - returns a pointer to the first occurrence of chr in s, if c is not found,
 * return a pointer to the character at index n
 *
 * @s: string to search in
 * @c: character to find
 * @n: number of bytes
 *
 * Note: this is a modified version of memchr for getline function
 *
 * Return: pointer to c if found. otherwise, NULL
 */
void *getline_memchr(char *s, char c, int n)
{
	char *p = s;

	while (n-- > 0)
	{
		if (*p == c)
			return ((void *)p);
		p++;
	}

	return ((void *)p);
}
