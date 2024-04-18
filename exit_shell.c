#include "shell.h"

void exit_shell(const char *command)
{
  if (strcmp(command, "exit") == 0)
  {
    exit(0);
  }
}