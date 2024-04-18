#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

void execute_command(char *command)
{
  pid_t pid;
  pid = fork();
  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0)
  {
    /* Child process */
    if (execlp(command, command, NULL) == -1)
    {
      fprintf(stderr, "./shell: No such file or directory\n");
      exit(EXIT_FAILURE);
    }
  }
  else
  {
    /* Parent process */
    int status;
    waitpid(pid, &status, 0);
  }
}

int main(void)
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

    /* Remove newline character */
    command[strcspn(command, "\n")] = '\0';

    token = strtok(command, " ");

    while (token != NULL)
    {
      token = strtok(NULL, " ");
    }

    execute_command(command);
  }

  return EXIT_SUCCESS;
}
/*gcc - Wall - Werror - pedantic all_shell.c - o all_shell*/