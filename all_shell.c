#include "shell.h"
int main()
{
  char command[MAX_COMMAND_LENGTH];

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

    execute_command(command);
  }

  return 0;
}
/*
int main()
{
  int status;
  int pid;

  pid = fork();

  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0)
  {
    execlp("ls", "ls", "-l", (char *)NULL);
    freopen("error.log", "a", stderr);
    perror("execlp");
    exit(EXIT_FAILURE);
  }
  else
  {

    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
    {
      printf("Child exited with status %d\n", WEXITSTATUS(status));
    }
    else
    {
      printf("Child exited abnormally\n");
    }
  }
  gcc -Wall -Werror -pedantic test_exit.c -o test_exit
return 0;
}
*/