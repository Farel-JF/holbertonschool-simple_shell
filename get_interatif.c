#include "shell.h"

void get_interatif()
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
    execute_command(command);
  }
}

void get_not_interatif(FILE *file)
{
    char input[MAX_INPUT_LENGTH];
    while (fgets(input, sizeof(input), file) != NULL)
    {
        /*Remove trailing newline character*/
        input[strcspn(input, "\n")] = '\0';

        /*Process the input (you can add your logic here)*/
        printf("You entered: %s\n", input);
    }
}
