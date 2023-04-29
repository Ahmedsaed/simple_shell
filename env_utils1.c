#include "main.h"

/* local helper function headers */
int _getenvLen(void);

/**
 * setup_env - Makes a copy of the original environment.
 * Return: 0 if successful, -1 if failed.
 */
int setup_env(void)
{
	int env_cnt, var_cnt, i;
	char **new_environ;

	env_cnt = _getenvLen();

	new_environ = malloc(sizeof(char *) * (env_cnt + 1));

	if (new_environ == NULL)
	{
		free(new_environ);
		return (-1);
	}

	for (i = 0; i < env_cnt; i++)
	{
		for (var_cnt = 0; environ[i][var_cnt] != '\0'; var_cnt++)
			;

		new_environ[i] = malloc(sizeof(char) * (var_cnt + 1));

		_memcpy(new_environ[i], environ[i], sizeof(char) * (var_cnt + 1));

		if (new_environ[i] == NULL)
		{
			free_env();
			return (-1);
		}
	}

	new_environ[i] = NULL;

	environ = new_environ;

	return (0);
}

/**
 * free_env - frees the memory that the environment copy
 *                                                takes.
 */
void free_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		free(environ[i]);
	free(environ);
}


/**
 * _getenv - Gets an environmental variable.
 *
 * @var: the name of the environmental variable.
 *
 * Return: Null if environmental variable doesnt exist.
 *		   Otherwise, value of environmental variable.
 */
char *_getenv(char *var)
{
	int idx, len;

	if (var == NULL)
		return (NULL);

	len = _strlen(var);

	if (environ != NULL)
	{
		for (idx = 0; environ[idx]; idx++)
		{
			if (_strncmp(var, environ[idx], len) == 0 && environ[idx][len] == '=')
				return (environ[idx] + len + 1);
		}
	}

	return (NULL);
}

/**
 * _setenv - sets an environmental variable,
 *			if exists, check if it is to be overwritten
 *			then overwrite it, otherwise dont overwrite.
 *			if doesn't exist, add it.
 *
 * @name: key
 * @value: value
 *
 * Return: 0 if successful, -1 if not.
 *
 * note: if envname refers to a string with "=",
 * setenv must fail. if name is empty, setenv must fail.
 * if setenv fails, must print EINVAL from <errno.h>.
 */
int _setenv(char *name, char *value)
{
	int env_len, name_len, val_len, i;
	char *ev;

	if (name == NULL || value == NULL || name[0] == '\0'
			|| _strchr(name, '=') != NULL)
	{
		print_err("Error: Invalid Arguments!\n");
		return (-1);
	}

	name_len = _strlen(name);
	val_len = _strlen(value);
	ev = malloc(name_len + val_len + 2);

	if (ev == NULL)
		return (-1);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0 &&
			environ[i][name_len] == '=')
		{
			_strcpy(ev, name);
			_strcat(ev, "=");
			_strcat(ev, value);

			free(environ[i]);
			environ[i] = ev;
			return (0);
		}
	}

	_strcpy(ev, name);
	_strcat(ev, "=");
	_strcat(ev, value);

	env_len = _getenvLen();

	environ = _realloc(environ, sizeof(char *) * (env_len),
			sizeof(char *) * (env_len + 2));

	environ[env_len] = ev;
	environ[env_len + 1] = NULL;
	return (0);
}

/**
 * _unsetenv - unsets an environmental variable
 *
 * @name: name of variable to be unset.
 *
 * Return: 0 on success, -1 on fail
 *
 * note: the algorithm unsets by shifting all
 *		  successive entries back one element.
 */
int _unsetenv(char *name)
{
	int len;
	char **ep, **sp;

	if (name == NULL || name[0] == '\0' || _strchr(name, '=') != NULL)
	{
		print_err("Error: Invalid Arguments!\n");
		return (-1);
	}

	len = _strlen(name);

	for (ep = environ; *ep;)
	{
		if (_strncmp(name, *ep, len) == 0 && (*ep)[len] == '=')
		{
			sp = ep;
			free(*sp);
			for (sp = ep; *sp; sp++)
				*sp = *(sp + 1);
		}
		else
			ep++;
	}

	return (0);
}


