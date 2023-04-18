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
			run_cmd(line_buffer, argv[0]);
		}
		else
			break;
	}

	free(line_buffer);
	print_str("\n");
	return (0);
}


/**
 * run_cmd - runs a command and waits for it to finish
 *
 * @line_buffer: the buffer that contains the command and it's arguments
 * @prog_name: string - program name
 *
 * Return: void.
 */
void run_cmd(char *line_buffer, char *prog_name)
{
	char *argv[MAX_ARGS_COUNT + 1], *argv_0;
	int child_pid, child_status, n, j;

	n = parse_cmd(line_buffer, argv);
	argv_0 = argv[0];
	argv[0] = parse_path(argv[0]);
	free(argv_0);

	if (n != 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			perror(prog_name);

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror(prog_name);
				for (j = 0; j < n; j++)
					free(argv[j]);
				free(line_buffer);

				_exit(1);
			}
		}
		else if (child_pid > 0)
			wait(&child_status);
	}

	for (j = 0; j < n; j++)
		free(argv[j]);
}

