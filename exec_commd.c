#include "shell.h"

void execute_command(char *command)
{
  pid_t pid;
  int status;

  pid = fork();

  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0)
  {
    /* Child process */
    if (strcmp(command, "exit") == 0)
    {
      exit(EXIT_SUCCESS);
    }
    else if (strcmp(command, "ls -l") == 0)
    {
      run_ls_l(command);
    }
    else
    {
      if (execlp(command, command, NULL) == -1)
      {
        fprintf(stderr, "./shell: No such file or directory\n");
        exit(EXIT_FAILURE);
      }
    }
  }
  else
  {
    waitpid(pid, &status, 0);
  }
}