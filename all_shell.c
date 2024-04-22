#include "shell.h"

int main()
{
  char command[MAX_COMMAND_LENGTH];

  while (1)
  {
    printf("cisfun$ ");

    if (fgets(command, sizeof(command), stdin) == NULL)
    {
      if (feof(stdin))
      {
        printf("^C\n");
        break;
      }
      else
      {
        perror("fgets");
        exit(EXIT_FAILURE);
      }
    }

    /*Remove newline character*/
    command[strcspn(command, "\n")] = '\0';
    /*execut command and choose function*/
    if (strcmp(command, "ls -l") == 0)
    {
      choose_command(command);
    }
  }
  return (0);
}
