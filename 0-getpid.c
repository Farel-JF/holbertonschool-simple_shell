#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid_parent;

    pid_parent = getppid();
    printf("PID du processus parent : %u\n", pid_parent);
    
    return 0;
}
