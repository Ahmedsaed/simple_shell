#include "main.h"

void update_alias_env(char *new_alias, char *new_value, int update_env);
char *setup_alias(char *alias, int len);

/**
 * print_alias - prints alias(es) from environ
 *
 * @name: the alias name to print it's value
 *
 * Note: if name is null, the function prints all aliases
 *
 * Return: 0 on sucess, 2 on failure
 */
int print_alias(char *name)
{
	int i, len;
	char *alias_env, *alias_value;

	alias_env = _getenv("alias");
	if (alias_env == NULL)
		return (2);

	if (name != NULL)
	{
		len = _strlen(name);
		alias_value = alias_env;
		for (i = 0; alias_env[i] != '\0'; i++)
			if (alias_env[i] == ':')
			{
				if (_strncmp(alias_value, name, len) == 0)
				{
					alias_env[i] = '\0';
					print_str(alias_value);
					print_str("\n");
					alias_env[i] = ':';
					break;
				}
				else
					alias_value = alias_env + i + 1;
			}
	}
	else
	{
		alias_value = alias_env;
		for (i = 0; alias_env[i] != '\0'; i++)
		{
			if (alias_env[i] == ':')
			{
				alias_env[i] = '\0';
				print_str(alias_value);
				print_str("\n");
				alias_value = alias_env + i + 1;
				alias_env[i] = ':';
			}
		}
	}

	return (0);
}

/**
 * set_alias - add a new alias or overwrite existing value
 *
 * @new_value: the new alias to set
 *
 * Return: 0 on sucess, 2 on failure
 */
int set_alias(char *new_value)
{
	int i, name_len, alias_env_len;
	char *alias_value, *alias_env, *new_alias;

	if (new_value == NULL)
	{
		print_err("Can't set alias: value is null");
		return (2);
	}

	name_len = _strchr(new_value, '=') - new_value;
	new_value = setup_alias(new_value, name_len);

	alias_env = _getenv("alias");
	if (alias_env == NULL)
	{
		new_alias = (char *)malloc(sizeof(char) * _strlen(new_value) + 2);
		new_alias[0] = '\0';
		update_alias_env(new_alias, new_value, 1);
		free(new_alias);
		free(new_value);
		return (2);
	}

	new_alias = (char *)malloc(sizeof(char) *
					(_strlen(new_value) +
					_strlen(alias_env) + 2));
	if (new_alias == NULL)
	{
		print_err("Can't set alias: couldn't allocate enough memory");
		return (2);
	}
	new_alias[0] = '\0';
	update_alias_env(new_alias, new_value, 0);

	alias_value = alias_env;
	for (i = 0; alias_env[i] != '\0'; i++)
		if (alias_env[i] == ':')
		{
			alias_env_len = _strchr(alias_value, '=') - alias_value;
			if (alias_env_len != name_len ||
				_strncmp(alias_value, new_value, name_len) != 0)
			{
				alias_env[i] = '\0';
				update_alias_env(new_alias, alias_value, 0);
				alias_env[i] = ':';
			}
			alias_value = alias_env + i + 1;
		}

	update_alias_env(new_alias, "", 1);
	free(new_alias);
	free(new_value);
	return (0);
}

/**
 * update_alias_env - appends new_alias to alias_env
 *
 * @new_alias: current alias env value
 * @new_value: string - the new alias to append
 * @update_env: boolean - if true update environ with the new alias
 *
 * Note: this is a helper function for set_alias
 */
void update_alias_env(char *new_alias, char *new_value, int update_env)
{
	_strcat(new_alias, new_value);

	if (new_value[0] != '\0')
		_strcat(new_alias, ":");

	if (update_env)
		_setenv("alias", new_alias);
}

/**
 * setup_alias - setup the alias to insert it in environ
 *
 * @alias: the string to be processed
 * @len: the len of alias name
 *
 * Return: pointer to string - the processed alias
 */
char *setup_alias(char *alias, int len)
{
	char *new_alias;

	if (alias[len + 1] == '\"')
	{
		alias[len + 1] = '\'';
		alias[_strlen(alias) - 1] = '\'';
	}

	if (alias[len + 1] == '\'')
		return (_strdup(alias));

	new_alias = malloc(sizeof(char) * (_strlen(alias) + 3));
	if (new_alias == NULL)
		return (_strdup(alias));

	new_alias[0] = '\0';
	_strncpy(new_alias, alias, len);
	_strcat(new_alias, "='");
	_strcat(new_alias, alias + len + 1);
	_strcat(new_alias, "\'");
	return (new_alias);
}
