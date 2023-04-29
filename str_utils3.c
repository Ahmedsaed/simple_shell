#include "main.h"

int digits(int num);

/**
 * _itoa - converts an integer to string
 *
 * @num: the integer to convert
 *
 * Return: the converted string
 */
char *_itoa(int num)
{
	char *buffer;
	int num_digits = digits(num);
	unsigned int n;

	buffer = malloc(sizeof(char) * (num_digits + 1));
	if (buffer == NULL)
		return (NULL);
	buffer[num_digits] = '\0';

	if (num < 0)
	{
		n = num * -1;
		buffer[0] = '-';
	}
	else
		n = num;

	num_digits--;
	do {
		buffer[num_digits] = (n % 10) + '0';
		n /= 10;
		num_digits--;
	} while (n > 0);

	return (buffer);
}

/**
 * digits - Counts the digit length of a number.
 * @num: The number to measure.
 *
 * Return: The digit length.
 */
int digits(int num)
{
	unsigned int num1;
	int len = 1;

	if (num < 0)
	{
		len++;
		num1 = num * -1;
	}
	else
		num1 = num;

	while (num1 > 9)
	{
		len++;
		num1 /= 10;
	}

	return (len);
}

/**
 * is_numeric - checks if a string could be converted to a number
 * or not
 *
 * @s: string to check
 *
 * Return: 1 is true, 0 is false
 */
int is_numeric(char *s)
{
	if (s == NULL)
		return (0);

	if (_strlen(s) == 0)
		return (0);

	if (s[0] == '-' || s[0] == '+')
		s++;

	while (*s != '\0')
	{
		if (!is_digit(*s))
			return (0);
		s++;
	}

	return (1);
}

/**
 * is_digit - checks if a character is a digit or not
 *
 * @c: the character to check
 *
 * Return: 1 is true, 0 is false
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
