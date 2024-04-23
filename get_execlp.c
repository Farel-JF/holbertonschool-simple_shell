
#include "shell.h"

int get_execlp(const char *file, const char *arg, ...)
{
    char *args_array[64];
    int status;
    const char *next_arg;
    int i = 0;

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
        return -1;
    } else if (pid == 0)
    {
        va_list args;
        va_start(args, arg);

        args_array[i++] = (char *)arg;

        while ((next_arg = va_arg(args, const char *)) != NULL && i < 63) {
            args_array[i++] = (char *)next_arg;
        }
        args_array[i] = NULL;

        execvp(file, args_array);
        fprintf(stderr, "%s: No such file or directory\n", file);
        exit(EXIT_FAILURE);
    }
    else
    {
        waitpid(pid, &status, 0);
    }
    return 0;
}
