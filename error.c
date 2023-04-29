#include "main.h"

/**
 * error_127 - print error message for command not found failures.
 *
 * @cmd: command name.
 */
void error_127(char *cmd)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return;

	len = _strlen(prog_name) + _strlen(hist_str) + _strlen(cmd) + 16;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return;
	}

	_strcpy(error, prog_name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, cmd);
	_strcat(error, ": not found\n");

	free(hist_str);
	print_err(error);
}

/**
 * error_126 - prints an error message for permission denied failures.
 *
 * @cmd: command name.
 */
void error_126(char *cmd)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return;

	len = _strlen(prog_name) + _strlen(hist_str) + _strlen(cmd) + 24;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return;
	}

	_strcpy(error, prog_name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, cmd);
	_strcat(error, ": Permission denied\n");

	free(hist_str);
	print_err(error);
}

/**
 * error_exit - prints an error message for exit errors.
 *
 * @value: the value that caused the error
 */
void error_exit(char *value)
{
	char *error, *hist_str;
	int len;

	hist_str = _itoa(hist);
	if (!hist_str)
		return;

	len = _strlen(prog_name) + _strlen(hist_str) + _strlen(value) + 27;
	error = malloc(sizeof(char) * (len + 1));
	if (!error)
	{
		free(hist_str);
		return;
	}

	_strcpy(error, prog_name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": exit: Illegal number: ");
	_strcat(error, value);
	_strcat(error, "\n");

	free(hist_str);
	print_err(error);
}
