#include "shell.h"
char *get_which(char *command, char **env)
{
  char *path = _getenv("PATH", env);
  char *path_token = strtok(path, ":");
  char filepath[MAX_COMMAND_WITH_PATH_LENGTH];
  char *command_path = _getenv("PATH", env), *token;
  struct stat st;
  do
  {
    snprintf(filepath, sizeof(filepath), "%s/%s", path_token, command);
    if (stat(command_path, &st) == 0)
    {
      command_path = strdup(filepath);
      free(path_token);
      return (command_path);
    }
    path_token = strtok(NULL, ":");
  } while (path_token != NULL);
}
