#include "main.h"

/**
 * _memcpy - copies memory block
 *			location up until a certain
 *              memory byte
 *
 * @dest: destination
 * @src: source
 * @n: until a certain memory byte.
 */

void _memcpy(void *dest, void *src, size_t n)
{
	size_t i;
	char *cdest = (char *)dest;
	char *csrc = (char *)src;

	for (i = 0; i < n; i++)
		cdest[i] = csrc[i];
}

/**
 * _realloc - reallocates a block of memory
 *
 * @ptr: pointer to malloc'ated block
 * @old_size: byte size of current block
 * @new_size: byte size of new block
 *
 * Return: pointer to the new memory block.
 */

void *_realloc(void *ptr, unsigned int old_size,
		unsigned int new_size)
{
	int size, i;
	char *p;

	if (ptr == NULL)
		return (malloc(new_size));
	if (new_size == 0)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);

	if (p == NULL)
		return (NULL);

	size = old_size < new_size ? old_size : new_size;

	for (i = 0; i < size; i++)
		p[i] = ((char *)ptr)[i];

	free(ptr);
	return (p);
}

/**
 * _memchr - returns a pointer to the first occurrence of chr in s
 *
 * @s: string to search in
 * @c: character to find
 * @n: number of bytes
 *
 * Return: pointer to c if found. otherwise, NULL
 */
void *_memchr(char *s, char c, int n)
{
	char *p = s;

	while (n-- > 0)
	{
		if (*p == c)
			return ((void *)p);
		p++;
	}

	return (NULL);
}
