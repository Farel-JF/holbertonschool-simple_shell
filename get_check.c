#include "shell.h"

/**
 * check_env - Check if a specified environment variable exists.
 * @variable: The environment variable to check.
 *
 * This function checks if the specified environment variable exists
 * in the current environment variables list. It returns true if found,
 * false otherwise.
 *
 * Return: 1 if the variable exists, 0 otherwise.
 */
int check_env(const char *variable)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, variable, strlen(variable)) == 0)
		{
			run_ls_l();
			return (true);
		}
	}
	return (false);
}