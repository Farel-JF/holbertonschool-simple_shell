#include "shell.h"

void run_ls_l()
{

  pid_t pid = fork();

  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0)
  {

    execlp("ls", "ls", "-l", NULL);

    perror("execlp");
    exit(EXIT_FAILURE);
  }
  else
  {
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
    {
      printf("Le processus enfant s'est terminé avec le code de sortie : %d\n", WEXITSTATUS(status));
    }
    else
    {
      printf("Le processus enfant s'est terminé de manière anormale.\n");
    }
  }
}
