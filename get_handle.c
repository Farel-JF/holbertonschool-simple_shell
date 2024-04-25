#include "shell.h"

/**
 * handle_eof - Handle EOF (End-of-File) condition on stdin.
 *
 * This function checks if the EOF indicator is set on the stand input (stdin).
 * If it is, the function exits the program with EXIT_SUCCESS.
 *
 * Return: 0 if EOF is not encountered, or if EOF handling is successful.
 */

int handle_eof()
{
	if (feof(stdin))
	{
		exit(EXIT_SUCCESS);
	}
	return 0;
}