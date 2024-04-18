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
    if (execlp(command, command, NULL) == -1)
    {
      fprintf(stderr, "./shell: No such file or directory\n");
      exit(EXIT_FAILURE);
    }
  }
  else
  {
    /* Parent process */
    
    waitpid(pid, &status, 0);
  }
}