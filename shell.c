#include "main.h"

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument list
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	size_t line_size = 0;
	char *line_buffer = NULL;

	(void)argv;
	(void)argc;

	while (1)
	{
		print_str("$ ");
		if (getline(&line_buffer, &line_size, stdin) != -1)
		{
			char *args[2];

			args[0] = line_buffer;
			args[1] = NULL;

			/* printf("%s", line_buffer); */

			if (execve(line_buffer, args, NULL) == -1)
				perror(argv[0]);
		}
		else
			break;
	}

	print_str("\n");
	free(line_buffer);
	return (0);
}
