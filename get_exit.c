#include "shell.h"

/**
 * get_exit - Check if the command is 'exit' and exit the shell if so.
 * @command: The command to check.
 *
 * This function checks if the given command is 'exit'. If it is, the
 * function terminates the shell with EXIT_SUCCESS status.
 */

void get_exit(char *command)
{
	if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
}
