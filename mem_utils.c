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

/**
 * _calloc - allocates memory and initializes it to zeros
 *
 * @count: This is the number of elements to be allocated
 * @size: the size of one element
 *
 * Return: pointer to allocated memory block
 */
void *_calloc(size_t count, size_t size)
{
	size_t i;
	void *ptr = malloc(count * size);

	if (ptr != NULL)
		for (i = 0; i < count * size; i++)
			*((char *)ptr + i) = 0;

	return (ptr);
}

/**
 * _recalloc - reallocates a block of memory
 *
 * @ptr: pointer to malloc'ated block
 * @old_size: byte size of current block
 * @new_size: byte size of new block
 *
 * Return: pointer to the new memory block.
 */

void *_recalloc(void *ptr, unsigned int old_size,
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

	for (; (unsigned int)i < new_size; i++)
		p[i] = '\0';

	free(ptr);
	return (p);
}
