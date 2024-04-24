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
    size_t path_len;
    char *path = getenv("PATH");
    char *path_copy;
    char *token;

    if (path == NULL)
    {
        fprintf(stderr, "Variable d'environnement PATH non trouvée.\n");
        return (-1);
    }

    path_len = strlen(path);
    path_copy = malloc(path_len + 1);
    if (path_copy == NULL)
    {
        fprintf(stderr, "Erreur lors de l'allocation mémoire.\n");
        return (-1);
    }
    strcpy(path_copy, path);

    token = strtok(path_copy, ":");
    while (token != NULL)
    {
	    size_t token_len = strlen(token);
	    size_t file_len = strlen(file);
	    char *full_path = malloc(token_len + file_len + 2);
	    if (full_path == NULL)
	    {
		    fprintf(stderr, "Erreur lors de l'allocation mémoire.\n");
		    free(path_copy);
		    return (-1);
	    }

	    sprintf(full_path, "%s/%s", token, file);
	    execv(full_path, argv);
	    free(full_path);
	    token = strtok(NULL, ":");
    }

    free(path_copy);

    fprintf(stderr, "Impossible de trouver l'exécutable '%s' dans le PATH.\n", file);
    return (-1);
}
