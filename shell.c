#include "main.h"

char *prog_name;

void shell_prompt(void);
void run_cmd(char *line_buffer);
int run_sys_cmd(char **argv, int n);
void sig_handler(int sig);

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

	signal(SIGINT, sig_handler);
	if (setup_env())
		return (-1);

	prog_name = argv[0];

	(void)argv;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			shell_prompt();
		if (_getline(&line_buffer, &line_size, STDIN_FILENO) != -1)
			run_cmd(line_buffer);
		else
			break;
	}

	free_env();
	free(line_buffer);

	if (isatty(STDIN_FILENO))
		print_str("\n");
	return (0);
}

/**
 * shell_prompt - displays shell prompt to stdout
 */
void shell_prompt(void)
{
	char cwd[PATH_MAX], *formatted_str;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		perror("getcwd() error");

	formatted_str = format_tilde(cwd);
	if (formatted_str != NULL)
		_strcpy(cwd, formatted_str);
	print_str(cwd);
	free(formatted_str);
	print_str("$ ");
}

/**
 * run_cmd - checks whether a command is built-in or system command and
 * calls the relevant function
 *
 * @line_buffer: the buffer that contains the command and it's arguments
 */
void run_cmd(char *line_buffer)
{
	int n, j, cmd_status;
	char *argv[MAX_ARGS_COUNT + 1], *cmd, *rest, sep;

	rest = line_buffer;

	while (rest != NULL)
	{
		split_cmds(rest, &sep, &cmd, &rest);
		cmd_status = 0;

		n = parse_cmd(cmd, argv);
		if (n == 0)
			break;
		handle_variables(argv);

		if (_strcmp(argv[0], "exit") == 0)
			exit_shell(line_buffer, argv);
		else if (_strcmp(argv[0], "env") == 0)
			_env();
		else if (_strcmp(argv[0], "setenv") == 0)
			cmd_status = (_setenv(argv[1], argv[2]) ? 1 : 0);
		else if (_strcmp(argv[0], "unsetenv") == 0)
			cmd_status = (_unsetenv(argv[1]) ? 1 : 0);
		else if (_strcmp(argv[0], "cd") == 0)
			cmd_status = change_dir(argv[1]);
		else if (_strcmp(argv[0], "alias") == 0)
			cmd_status = alias(argv);
		else
			cmd_status = run_sys_cmd(argv, n);

		for (j = 0; j < n; j++)
			free(argv[j]);

		if (sep == '|' && cmd_status == 0)
			break;
		else if (sep == '&' && cmd_status != 0)
			break;
	}
}


/**
 * run_sys_cmd - runs a command and waits for it to finish
 *
 * @argv: array of strings storing the command and it's arguments
 * @n: number of arguments in argv
 *
 * Return: exit status code of child process
 */
int run_sys_cmd(char **argv, int n)
{
	char *prog_path;
	int child_pid, child_status = -1, j;
	struct stat st;

	prog_path = parse_path(argv[0]);
	if (stat(prog_path, &st) != 0)
	{
		perror(prog_name);
		return (1);
	}

	child_pid = fork();
	if (child_pid == -1)
		perror(prog_name);

	if (child_pid == 0)
	{
		if (execve(prog_path, argv, environ) == -1)
		{
			perror(prog_name);
			for (j = 0; j < n; j++)
				free(argv[j]);
			free(prog_path);

			_exit(1);
		}
	}
	else if (child_pid > 0)
		wait(&child_status);

	free(prog_path);
	return (child_status);
}

/**
 * sig_handler - handle SIGINT signal
 *
 * @sig: signal value
 */
void sig_handler(int sig)
{
	print_str("\n");
	shell_prompt();
	(void) sig;
}
