#include "shell.h"

void run_ls_l()
{
  const char *arg0 = "ls";
  const char *arg1 = "-l";

  pid_t pid = fork();

  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0)
  {

    get_exceclp(arg0, arg1, NULL);

    perror("execlp");
    exit(EXIT_FAILURE);
  }
  else
  {
    int status;
    waitpid(pid, &status, 0);
  }
}
