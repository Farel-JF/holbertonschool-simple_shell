#include "shell.h"

char *get_which(char *command, char **env)
{
    struct stat st;
    char *copy_path = strdup(_getenv("PATH", env));
    char *path_token = strtok(copy_path, ":");
    char filepath[MAX_COMMAND_WITH_PATH_LENGTH];
    char *command_path = NULL;

    if (path_token != NULL)
    {
        do
        {
            snprintf(filepath, sizeof(filepath), "%s/%s", path_token, command);
            if (stat(filepath, &st) == 0)
            {
                command_path = strdup(filepath);
                break;
            }
            path_token = strtok(NULL, ":");
        } while (path_token != NULL);
    }
    free(copy_path);
    return command_path;
}



char *_getenv(const char *name, char **env)
{
    int i, j;

    for (i = 0; env[i]; i++)
    {
        for (j = 0; env[i][j]; j++)
        {
            if (env[i][j] == name[j])
                continue;
            else if (env[i][j] == '=' && name[j] == '\0')
            {
                return (&env[i][j + 1]);
            }
                else
                break;
        }
    }
    return (NULL);
}
