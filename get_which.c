#include "shell.h"

char *get_which(char *command, char **env)
{
    struct stat st;
  char *copy_path;
  char *path_token;
  char filepath[MAX_COMMAND_WITH_PATH_LENGTH];
  char *command_path;

  copy_path = _getenv("PATH", env);
  command_path = _getenv("PATH", env);

    if (copy_path != NULL)
    {
        copy_path = strdup(_getenv("PATH", env));
    }

    path_token = strtok(copy_path, ":");

    if (path_token != NULL)
    {
        do
        {
        snprintf(filepath, sizeof(filepath), "%s/%s", path_token, command);
        if (stat(command_path, &st) == 0)
        {
            free(path_token);
            return (strdup(command_path));
        }
        path_token = strtok(NULL, ":");
        } while (path_token != NULL);
    }
    free(copy_path);
    return(NULL);
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
