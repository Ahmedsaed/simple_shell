#include "main.h"

/**
 * _substr - extracts characters from source
 *			                between m and n.
 *
 * @src: string
 * @m: first character
 * @n: second character
 * Return: return string between m & n
 */

char *_substr(char *src, int m, int n)
{
	int len = n - m, i;
	char *ptr;

	ptr = (char *)malloc(sizeof(char) * (len + 1));
	m--;

	for (i = m; i < n && (*(src + i) != '\0'); i++)
	{
		*ptr = *(src + i);
		ptr++;
	}

	*ptr = '\0';

	return ((ptr - len - 1));
}
