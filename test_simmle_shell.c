#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command)
{
  if (access(command, X_OK) == -1)
  {
    fprintf(stderr, "%s: command not found\n", command);
    return;
  }

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
  char *token;
  char *path = getenv("PATH");

  if (path == NULL)
  {
    fprintf(stderr, "Error: PATH environment variable not set\n");
    return EXIT_FAILURE;
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

    // Remove newline character
    command[strcspn(command, "\n")] = '\0';

    token = strtok(command, " ");

    // Reset arg_count for each command
    int arg_count = 0;

    while (token != NULL)
    {
      arg_count++;
      token = strtok(NULL, " ");
    }

    // Execute the command only if it exists
    execute_command(command);
  }

  return 0;
}
/*gcc - Wall - Werror - pedantic args_shell.c - o args_shell*/