#include "shell.h"

int manage_command(char *command)
{
  /*Remove newline character*/
  command[strcspn(command, "\n")] = '\0';

  execute_command(command);

  return (0);
}