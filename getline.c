#include "main.h"

/* local helper function headers */
int update_buffer(char **buffer,
		char **buffer_ptr,
		size_t *current_buffer_size,
		size_t bytes_read);
int line_len(char delim, char *buffer);
int alloc_buffer(char **buffer, int old_size, int new_size);
int update_lineptr(char **lineptr,
		size_t *n,
		char delim,
		char **buffer_ptr,
		size_t *total_bytes);
void free_buffer(char **buffer,
		UNUSED char **buffer_ptr,
		UNUSED size_t *current_buffer_size,
		UNUSED size_t *bytes_read);

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
int _getline(char **lineptr, size_t *n, int stream)
{
	static char *buffer, *buffer_ptr;
	static size_t current_buffer_size, bytes_read;
	size_t total_bytes = 0;
	int r = -1;

	if (lineptr == NULL || n == NULL)
		return (-1);

	if (buffer == NULL)
		if (update_buffer(&buffer, &buffer_ptr, &current_buffer_size, bytes_read))
			return (-1);

	while (1)
	{
		if (buffer_ptr < buffer + bytes_read)
		{
			if (update_lineptr(lineptr, n,
						(r == 0) ? '\0' : '\n',
						&buffer_ptr, &total_bytes) == 0)
			{
				if (buffer_ptr == buffer + bytes_read)
					free_buffer(&buffer, &buffer_ptr, &current_buffer_size, &bytes_read);

				return (total_bytes);
			}
		}

		if (buffer + bytes_read == buffer + current_buffer_size)
			if (update_buffer(&buffer, &buffer_ptr, &current_buffer_size, bytes_read))
				return (-1);

		r = read(stream, buffer + bytes_read,
				current_buffer_size - bytes_read);

		if (r == 0 && !(buffer_ptr < buffer + bytes_read))
		{
			free_buffer(&buffer, &buffer_ptr, &current_buffer_size, &bytes_read);
			return (-1);
		}
		else if (r < 0)
		{
			perror(prog_name);
			return (-1);
		}

		bytes_read += r;
	}
}

/**
 * update_lineptr - helper function for getline that updates
 * lineptr using buffer
 *
 * @lineptr: pointer to the lineptr variable to update it's value
 * @n: pointer to the variable that stores the size of lineptr
 * @delim: the delimiter for finding next line
 * @buffer_ptr: a pointer to a byte in buffer
 * @total_bytes: total number of bytes returned
 *
 * Return: 0 on sucess, -1 on failure
 */
int update_lineptr(char **lineptr, size_t *n, char delim,
		char **buffer_ptr, size_t *total_bytes)
{
	int line_len_b;

	line_len_b = line_len(delim, *buffer_ptr);
	if (line_len_b == -1)
		return (-1);

	if (alloc_buffer(lineptr, *n, line_len_b + 1) == -1)
		return (-1);

	/* *n = ((size_t)line_len_b > *n) ? (size_t)line_len_b : *n; */
	*n = (size_t)line_len_b + 1;

	_strncpy(*lineptr + *total_bytes, *buffer_ptr, line_len_b);
	*buffer_ptr += line_len_b + 1;
	*total_bytes += line_len_b + 1;

	return (0);
}

/**
 * alloc_buffer - allocates n bytes of memory to buffer
 *
 * Note:
 *	- If buffer has data, it copies the data to the new buffer
 *	- if buffer is null, it allocates new memory
 *
 * @buffer: pointer to point to the new allocated memory
 * @old_size: the size of the buffer before allocation
 * @new_size: the size of the buffer after allocation
 *
 * Return: 0 on success, -1 on fialure
 */
int alloc_buffer(char **buffer, int old_size, int new_size)
{
	/* char *new_buffer; */

	if (buffer == NULL)
		return (-1);

	if (*buffer == NULL)
	{
		*buffer = _calloc(new_size + 1, sizeof(char));
		if (*buffer == NULL)
			return (-1);
		return (0);
	}
	else
	{
		*buffer = _recalloc(*buffer, old_size, new_size + 1);
		if (*buffer == NULL)
			return (-1);
		return (0);
	}
}

/**
 * line_len - returns the length of the new line
 *
 * @delim: the delimiter that is used to find the new line
 * @buffer: the buffer which contains the new line
 *
 * Return: length of new line or -1 on fialure
 */
int line_len(char delim, char *buffer)
{
	char *new_line;

	new_line = _memchr(buffer, delim, _strlen(buffer) + 1);
	if (new_line == NULL)
		return (-1);

	return (new_line - buffer);
}

/**
 * update_buffer - updates buffer size and pointers and
 * allocates more memory
 *
 * @buffer: pointer to the buffer to update
 * @buffer_ptr: a pointer in getline that should be
 * updated after allocating memory
 * @current_buffer_size: the size of the current buffer
 * @bytes_read: a variable from getline that's used to update buffer_ptr
 *
 * Return: 0 on sucess, -1 on failure
 */
int update_buffer(char **buffer, char **buffer_ptr,
		size_t *current_buffer_size, size_t bytes_read)
{
	int n;

	if (buffer == NULL || buffer_ptr == NULL)
		return (-1);

	if (*buffer == NULL || *current_buffer_size == 0)
		*current_buffer_size = BUFFER_SIZE;
	else
		*current_buffer_size += BUFFER_SIZE;

	n = alloc_buffer(buffer,
			*current_buffer_size - BUFFER_SIZE,
			*current_buffer_size);
	if (n == -1)
		return (-1);

	*buffer_ptr = *buffer +	bytes_read;

	return (0);
}


