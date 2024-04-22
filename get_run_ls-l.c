#include "shell.h"
void run_ls_l()
{
    const char *const avs[] = {"/bin/ls", "-l", NULL};
    char *const envp[] = {NULL};
    int status;

    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        execve("/bin/ls", (char *const *)avs, envp);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
}


