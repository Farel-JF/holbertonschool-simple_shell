#include "shell.h"

/**
 * execute_command - Execute a given command.
 * @command: The command to be executed.
 *
 * This function takes a command as input, parses it into separate arguments,
 * and executes it using execvp. It handles forking a new process and waiting
 * for its completion.
 */
void execute_command(char *command)
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
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "./shell: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
