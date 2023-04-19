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
			run_cmd(line_buffer, argv[0]);
		else
		{
			print_str("\nexit");
			break;
		}
	}

	free(line_buffer);
	print_str("\n");
	return (0);
}

/**
 * run_cmd - checks whether a command is built-in or system command and
 * calls the relevant function
 *
 * @line_buffer: the buffer that contains the command and it's arguments
 * @prog_name: string - program name
 */
void run_cmd(char *line_buffer, char *prog_name)
{
	int n, j;
	char *argv[MAX_ARGS_COUNT + 1];

	n = parse_cmd(line_buffer, argv);

	if (_strcmp(argv[0], "exit") == 0)
		exit_shell(line_buffer, argv);
	else if (_strcmp(argv[0], "env") == 0)
		_env();
	else if (n != 0)
		run_sys_cmd(prog_name, argv, n);

	for (j = 0; j < n; j++)
		free(argv[j]);
}


/**
 * run_sys_cmd - runs a command and waits for it to finish
 *
 * @prog_name: string - program name
 * @argv: array of strings storing the command and it's arguments
 * @n: number of arguments in argv
 *
 * Return: void.
 */
void run_sys_cmd(char *prog_name, char **argv, int n)
{
	char *argv_0;
	int child_pid, child_status, j;

	argv_0 = argv[0];
	argv[0] = parse_path(argv[0]);
	free(argv_0);

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

			_exit(1);
		}
	}
	else if (child_pid > 0)
		wait(&child_status);
}
