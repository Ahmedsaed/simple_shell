#include "main.h"

/**
 * error_127 - prints an error for command not found failures
 *
 * @cmd: the name of the command
 */
void error_127(char *cmd)
{
	char *error, *hist_str;

	hist_str = _itoa(hist_count);
	if (hist_str == NULL)
		return;

	error = malloc(sizeof(char) *
				(_strlen(prog_name) +
				_strlen(hist_str) +
				_strlen(cmd) + 16 + 1));
	if (error == NULL)
	{
		free(hist_str);
		return;
	}

	_strcpy(error, prog_name);
	_strcat(error, ": ");
	_strcat(error, hist_str);
	_strcat(error, ": ");
	_strcat(error, cmd);
	_strcat(error, ": command not found\n");

	print_err(error);

	free(hist_str);
}
