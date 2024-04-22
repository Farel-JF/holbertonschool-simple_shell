#include "shell.h"

void execute_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {

        if (strcmp(command, "ls -l") == 0)
        {
            get_execlp("/bin/ls", "ls", "-l", NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        }
        else if (strcmp(command, "ls -l /tmp") == 0)
        {
            run_ls_l();
        }
        else
        {
            get_execlp(command, command, NULL);

        }
    }
    else
    {
        waitpid(pid, &status, 0);

    }
}
