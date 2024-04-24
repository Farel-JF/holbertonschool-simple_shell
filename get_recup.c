#include "shell.h"
/**
 * get_recup - Construct a string with status, filename, and command.
 * @fname: The filename.
 * @numcount: The number count.
 * @cmd: The command.
 * @status: The status.
 *
 * This function dynamically allocates memory to construct a string
 * containing the provided status, filename, and command. It concatenates
 * these elements with appropriate spacing. The caller is responsible for
 * freeing the memory allocated for the returned string.
 *
 * Return: A pointer to the constructed string, or NULL on failure.
 */

char *get_recup(char *fname, int numcount, char *cmd, const char *status)
{
	char *result = malloc(numcount + strlen(status) + strlen(fname)
	+ strlen(cmd) + 3);

	if (result == NULL)
	{
		perror("Allocation failed");
		return (NULL);
	}
	strcpy(result, status);
	strcat(result, " ");
	strcat(result, fname);
	strcat(result, " ");
	strcat(result, cmd);

	free(result);
	return (result);
}
