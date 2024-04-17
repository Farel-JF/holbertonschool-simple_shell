#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100

void run_command(char *command)
{
    if (system(command) == -1)
    {
        perror("Error executing command");
    }
}

void list_directory_contents()
{
    run_command("ls -l");
}

int main()
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {
        printf("cisfun$ ");
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            break;
        }

        // Remove trailing newline
        command[strcspn(command, "\n")] = 0;

        if (strcmp(command, "exit") == 0)
        {
            break;
        }

        if (strcmp(command, "l") == 0)
        {
            list_directory_contents();
            continue;
        }

        run_command(command);
    }

    return 0;
}
/*gcc -Wall -Werror -pedantic shell.c -o shell*/