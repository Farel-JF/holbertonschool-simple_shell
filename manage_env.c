#include "shell.h"

int manage_env(void)
{
  char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

  if (execve(argv[0], argv, NULL) == -1)
  {
    perror("Error:");
  }
  printf("After execve\n");
  return (0);
}