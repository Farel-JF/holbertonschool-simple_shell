#include "shell.h"

/**
 * get_which - Find the full path of a command in the PATH envr variable.
 * @command: The command to search for.
 * @envp: The environment variables.
 *
 * This function searches for the full path of the given command by iterating
 * through the directories listed in the PATH environment variable. It returns
 * the full path if found, otherwise NULL.
 *
 * Return: A pointer to the full path of the command, or NULL if not found.
 */
char *get_which(char *command, char **envp)
{
	struct stat st;
	char *path = _getenv("PATH", envp);
	char *path_copy = strdup(path);
	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		char filepath[MAX_PATH_LENGTH];

		snprintf(filepath, sizeof(filepath), "%s/%s", token, command);
		if (stat(filepath, &st) == 0 && S_ISREG(st.st_mode) &&
	(st.st_mode & S_IXUSR))

		{
			char *command_path = strdup(filepath);

			free(path_copy);
			return (command_path);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable.
 * @env: The environment variables.
 *
 * This function retrieves the value of the specified environment variable
 * from the provided environment variables list.
 *
 * Return: A pointer to the value of the envr variable, or NULL if not found.
 */
char *_getenv(const char *name, char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		if (strncmp(env[i], name, strlen(name)) == 0 &&
				env[i][strlen(name)] == '=')
		{
			return (&env[i][strlen(name) + 1]);
			check_env(name);
		}
	}
	return (NULL);
}
