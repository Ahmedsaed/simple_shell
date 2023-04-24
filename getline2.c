#include "main.h"

/**
 * free_buffer - frees the memory allocated for getline
 *
 * @buffer: pointer to the memory block that should be freed
 * @buffer_ptr: a pointer used by getline to index the buffer which should
 * reset to null after freeing the buffer
 * @current_buffer_size: the current size of buffer
 * @bytes_read: number of bytes read from stdin
 */
void free_buffer(char **buffer,
		UNUSED char **buffer_ptr,
		UNUSED size_t *current_buffer_size,
		UNUSED size_t *bytes_read)
{
	free(*buffer);
	*buffer = NULL;
	*buffer_ptr = NULL;
	*current_buffer_size = 0;
	*bytes_read = 0;
}


