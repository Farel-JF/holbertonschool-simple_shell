#include "shell.h"

void choose_command(char *command)
{
  if (strcmp(command, "ls") == 0)
  {
    execute_command(command);
  }
  else if (strcmp(command, "ls -l") == 0)
  {
    run_ls_l();
  }
  else if (strcmp(command, "exit") == 0)
  {
    exit_shell(command);
  }
  else
  {
    printf("./shell: No such file or directory\n");
  }
}
