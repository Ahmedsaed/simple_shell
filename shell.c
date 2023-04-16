#include "main.h"

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument list
 * @envp: environment variables
 * Return: 0 on success
 */

int main(int argc, char **argv, char *envp[])
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
			run_cmd(line_buffer, argv[0], envp);
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
 * @prog_name: string - program name
 * @env: environment variables
 */
void run_cmd(char *line_buffer, char *prog_name, char *env[])
{
	char *argv[MAX_ARGS + 1];
	int child_pid, child_status, n, j;

	n = parse_cmd(line_buffer, argv);

	if (n != 0)
	{
		child_pid = fork();
		if (child_pid == -1)
			perror(prog_name);

		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			{
				perror(prog_name);
				for (j = 0; j < n; j++)
					free(argv[j]);
				free(line_buffer);

				_exit(-1);
			}
		}
		else if (child_pid > 0)
			wait(&child_status);
	}

	for (j = 0; j < n; j++)
		free(argv[j]);
}

