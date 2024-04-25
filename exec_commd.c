#include "shell.h"

/**
 * execute_command - Execute a command.
 * @command: The command to execute.
 * @env: The environment variables.
 *
 * Return: The exit status of the command.
 */
int execute_command(char *command, char *env[])
{
	pid_t pid;
	int status;
	char *args[MAX_ARGS];
	int i = 0;
	char *full_path;
	char *token;

	token = strtok(command, " ");
	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;

	if (command[0] == '/')
	{
		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (_execvp(args[0], args, env) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	else
	{
		full_path = get_which(command, env);
		if (full_path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", command);
			return (-1);
		}
		else
		{
			pid = fork();

			if (pid == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				if (execve(full_path, args, env) == -1)
				{
					perror("execve");
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				waitpid(pid, &status, 0);
			}
			free(full_path);
		}
	}

	return (0);
}
