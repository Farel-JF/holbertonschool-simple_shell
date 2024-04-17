#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  pid_t pid = fork();
  if (pid == -1)
  {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  else if (pid == 0)
  {
    // Child process
    execlp("ls", "ls", "-l", (char *)NULL);
    // Redirect stderr to a file
    freopen("error.log", "a", stderr);
    // Print error message to the file
    perror("execlp");
    exit(EXIT_FAILURE);
  }
  else
  {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
    {
      printf("Child exited with status %d\n", WEXITSTATUS(status));
    }
    else
    {
      printf("Child exited abnormally\n");
    }
  }
  return 0;
}
/*gcc -Wall -Werror -pedantic test_exit.c -o test_exit*/