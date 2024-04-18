#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

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
  char *token;
  int arg_count = 0;

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

    while (token != NULL)
    {
      arg_count++;
      token = strtok(NULL, " ");
    }

    execute_command(command);
  }

  return 0;
}
/*gcc - Wall - Werror - pedantic args_shell.c - o args_shell*/