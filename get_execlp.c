#include "shell.h"

/**
 * _execlp - Execute a file with variable arguments.
 * @file: The path of the file to execute.
 * @arg: The first argument to the file.
 * @...: Optional additional arguments, terminated by NULL.
 * @env: The environment variables to be passed to the command.
 * This function executes a file with variable arguments using execvp.
 * It forks a new process, builds an argument array from the provided
 * arguments, and executes the file with execvp. It waits for the
 * execution to finish before returning.
 *
 * Return: 0 on success, -1 on failure.
 */
int _execlp(const char *file, const char *arg, char *env[], ...)
{
	char *args_array[64];
	int status;
	const char *next_arg;
	pid_t pid;
	va_list args;
	int i = 0;

	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		return (127);
	}
	else if (pid == 0)
	{
		va_start(args, env);
		args_array[i++] = (char *)arg;

		while ((next_arg = va_arg(args, const char *)) != NULL && i < 63)
		{
			args_array[i++] = (char *)next_arg;
		}
		va_end(args);
		args_array[i] = NULL;
		_execvp(file, args_array, env);
		fprintf(stderr, "%s: No such f or directory\n", file);
		exit(-1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}
