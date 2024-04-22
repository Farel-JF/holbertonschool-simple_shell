#include "shell.h"

void run_ls_l()
{
  const char *arg0 = "ls";
  const char *arg1 = "-l";

  char *const args[] = {"/bin/ls", arg0, arg1, NULL};
  char *const envp[] = {NULL};
  pid_t pid = fork();

  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0)
  {
    execve(args[0], args, envp);
    perror("execve");
    exit(EXIT_FAILURE);
  }
  else
  {
    int status;
    waitpid(pid, &status, 0);
  }
}

int main()
{
  run_ls_l();
  return 0;
}
