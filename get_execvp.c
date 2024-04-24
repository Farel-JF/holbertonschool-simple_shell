#include "shell.h"

/**
 * get_execvp - Search for an executable file in PATH and execute it
 * @file: The name of the file to execute
 * @argv: Array of pointers to arguments for the executable
 *
 * Return: Upon success, execvp() does not return. On failure, -1 is returned,
 * and errno is set appropriately.
 */
int get_execvp(const char *file, char *const argv[])
{
	execvp(file, argv);

	perror("my_execvp failed");
	return (-1);
}
