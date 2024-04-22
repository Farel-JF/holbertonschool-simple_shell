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
        handle_eof();
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

    if (strcmp(command, "ls -l") == 0) {
            run_ls_l();
        } else if (strcmp(command, "exit") == 0) {
            exit(EXIT_SUCCESS);
        } else {
            printf("Commande non reconnue : %s\n", command);
        }
    /*execut command and choose function*/
    if (strlen(command) == 0)
    {
      continue;
    }
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
