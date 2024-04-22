#include "shell.h"

void get_exit(char *command)
{
  if (strcmp(command, "exit") == 0)
  {
    exit(0);
  }
}
