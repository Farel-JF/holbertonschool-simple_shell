#include "shell.h"

/**
 * get_execlp - Execute a file with variable arguments.
 * @file: The path of the file to execute.
 * @arg: The first argument to the file.
 * @...: Optional additional arguments, terminated by NULL.
 *
 * This function executes a file with variable arguments using execvp.
 * It forks a new process, builds an argument array from the provided
 * arguments, and executes the file with execvp. It waits for the
 * execution to finish before returning.
 *
 * Return: 0 on success, -1 on failure.
 */

int get_execlp(const char *file, const char *arg, ...)
{
	char *args_array[64];
	int status;
	const char *next_arg;
	va_list args;

	int i = 0;

	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		va_start(args, arg);
		args_array[i++] = (char *)arg;

		while ((next_arg = va_arg(args, const char *)) != NULL && i < 63)
		{
			args_array[i++] = (char *)next_arg;
		}

		args_array[i] = NULL;
		execve(file, args_array, environ);
		fprintf(stderr, "%s: No such file or directory\n", file);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
	return (0);
}
