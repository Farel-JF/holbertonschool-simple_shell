#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

#define MAX_COMMAND_WITH_PATH_LENGTH (MAX_PATH_LENGTH + MAX_COMMAND_LENGTH + 2)
void execute_command(char *command)
{
  pid_t pid = fork();

  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0)
  {
    // Child process
    if (execlp(command, command, NULL) == -1)
    {
      fprintf(stderr, "./shell: No such file or directory\n");
      exit(EXIT_FAILURE);
    }
  }
  else
  {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
  }
}

int main(int argc, char *argv[])
{
  char command[MAX_COMMAND_LENGTH];
  char command_with_path[MAX_COMMAND_LENGTH];
  char *token;
  char *tokken;
  int arg_count = 0;
  char *path;

  path = getenv("PATH");

  if (path == NULL)
  {
    fprintf(stderr, "Error : PATH environment variable not set\n");
    return (EXIT_FAILURE);
  }

  while (1)
  {
    printf("cisfun$ ");

    if (fgets(command, sizeof(command), stdin) == NULL)
    {
      if (feof(stdin))
      {
        printf("^C\n");
        break;
      }
      else
      {
        perror("fgets");
        exit(EXIT_FAILURE);
      }
    }

    /*Remove newline character*/
    command[strcspn(command, "\n")] = '\0';

    token = strtok(command, " ");

    while (token != NULL)
    {
      arg_count++;
      token = strtok(NULL, " ");

      execute_command(command);
    }

    /*Remove newline character*/
    command[strcspn(command, "\n")] = '\0';
    /*Initialize command_with_path*/
    tokken = strtok(path, ":");

    while (tokken != NULL)
    {
      snprintf(command_with_path, sizeof(command_with_path), "%s/%s", tokken, command);
      if (access(command_with_path, X_OK) != -1)
      {
        execute_command(command_with_path);
        break;
      }
      tokken = strtok(NULL, ":");
    }

    if (tokken == NULL)
    {
      fprintf(stderr, "Error: Command not found\n");
    }
  }
  return (0);
}
/*gcc - Wall - Werror - pedantic path_shell.c - o path_shell*/
