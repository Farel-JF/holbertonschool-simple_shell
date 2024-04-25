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
	char *token = strtok(command, " ");

	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;
	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (get_execvp(args[0], args, env) == -1)
		{
			printf("Votre chaine de caractères ic");
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}
