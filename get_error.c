#include "shell.h"

/**
 * _ferror - Check for error indicator on a stream
 * @stream: The stream to check
 *
 * This function checks if the error indicator is set on the specified stream.
 *
 * Return: 1 if the error indicator is set, 0 otherwise.
 */
int _ferror(FILE *stream)
{
	if (stream == NULL)
	{
		errno = EINVAL;
		return (1);
	}
	if (fileno(stream) == -1)
	{
		errno = EBADF;
		return (1);
	}
	if (errno != 0)
	{
		return (1);
	}
	return (0);
}
