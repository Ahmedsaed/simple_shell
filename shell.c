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
	char *argv[10];
	int child_pid;
	int child_status;

	parse_cmd(line_buffer, argv);

	child_pid = fork();
	if (child_pid == 0)
		if (execve(argv[0], argv))
			return (-1);
	else
		wait(child_status);
	
	return (0);
}


