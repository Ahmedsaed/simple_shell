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
			if (run_cmd(line_buffer) == -1)
				perror(argv[0]);
		}
		else
			break;
	}

	print_str("\n");
	free(line_buffer);
	return (0);
}


/**
 * run_cmd - runs a command and waits for it to finish
 *
 * @line_buffer: the buffer that contains the command and it's arguments
 *
 * Return: 0 on success, -1 on failure
 */
int run_cmd(char *line_buffer)
{
	char *argv[2]; /*  MAX_ARGS + 1*/
	int child_pid, child_status, n, j;

	n = parse_cmd(line_buffer, argv);

	child_pid = fork();
	if (child_pid == -1)
		return (-1);

	if (child_pid == 0)
	{
		printf("%s\n", argv[0]);
		printf("%p   %d\n", argv[1], n);
		if (execve(argv[0], argv, NULL) == -1)
			return (-1);
	}
	else
		wait(&child_status);

	for (j = 0; j < n; j++)
		free(argv[j]);

	return (0);
}


