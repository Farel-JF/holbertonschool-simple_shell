#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 100

int main()
{
    int i;
    pid_t pid;
    int status;
     
    for (i = 0; i < 5; i++)
    {
        pid = fork();

        if (pid == -1)
        {
            perror("Error forking");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            printf("Child %d executing...\n", i + 1);
            execlp("ls", "ls", "-l", "/tmp", NULL);

            perror("execl echoué");
            exit(EXIT_FAILURE);
        }
        else 
        {
            waitpid(pid, &status, 0);

            if (WIFEXITED(status)) {
                printf("Child %d exited with status: %d\n", i + 1, WEXITSTATUS(status));
            } else {
                printf("Child %d terminated abnormally\n", i + 1);
            }
         }
    }
}

/*gcc -Wall -Werror -pedantic c_pid.c -o c_pid*/
/*alias l='./exec*/